#include "Actor.h"
#include "Outfit.h"
#include "EquipConditions.h"
#include "Offsets.h"
#include "Settings.h"
#include "ActorData.h"
#include <ranges>

namespace Gotobed
{	
	namespace
	{
		template<std::ranges::input_range R1, std::ranges::input_range R2, std::weakly_incrementable O, class Comp>
		void set_difference(R1&& r1, R2&& r2, O result, Comp comp) {
			std::ranges::copy_if(r1, result, [&](auto const& e1) {
				return std::ranges::find_if(r2, [&](auto const& e2) { return comp(e1, e2); }) == r2.end();
			});
		}

		void do_equip(Actor& a_actor, EquipParams const& a_params) {
			if (a_params.count) {
				if (a_params.count > 0) {
					a_actor.EquipItem(a_params.item, nullptr, a_params.count, a_params.slot);
				} else {
					a_actor.UnequipItem(a_params.item, nullptr, -a_params.count, a_params.slot);
				}
			}
		};

		template<std::ranges::input_range R>
		void do_equip(Actor& a_actor, R const& a_seq) {
			for (auto const& e : a_seq) {
				do_equip(a_actor, e);
			}
		}

		template<std::ranges::input_range R>
		void do_reverse_equip(Actor& a_actor, R const& a_seq) {
			do_equip(a_actor, a_seq | std::views::reverse | std::views::transform([](auto e) { e.count = -e.count; return e; }));
		}

		EquipSequence get_worn_items(Actor& a_actor) {
			EquipSequence items;
			auto inv = a_actor.GetInventory();

			for (auto const& [item, itemData] : inv) {
				auto const& [count, invData] = itemData;
				if (invData->extraLists) {
					for (auto const& extraList : *invData->extraLists) {
						if (extraList && (extraList->HasType(RE::ExtraDataType::kWorn) || extraList->HasType(RE::ExtraDataType::kWornLeft))) {
							EquipParams params;
							params.item = item;
							params.count = extraList->GetCount();

							if (item->IsWeapon()) {
								auto dom = RE::BGSDefaultObjectManager::GetSingleton();
								auto left = extraList->HasType(RE::ExtraDataType::kWornLeft);
								params.slot = dom->GetObject<RE::BGSEquipSlot>(left ? RE::DEFAULT_OBJECTS::kLeftHandEquip : RE::DEFAULT_OBJECTS::kRightHandEquip);
							}

							items.push_back(std::move(params));
						}
					}
				}
			}

			return items;
		}
	}

	RE::BGSLocation* Actor::GetCurrentLocation() {
		using func_t = decltype(&Actor::GetCurrentLocation);
		REL::Relocation<func_t> func{Offsets::TESObjectREFR::GetCurrentLocation};
		return func(this);
	}

	void Actor::EquipItem(RE::TESBoundObject* a_item, RE::ExtraDataList* a_extraData, std::uint32_t a_count, const RE::BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow) {
		RE::ActorEquipManager::GetSingleton()->EquipObject(this, a_item, a_extraData, a_count, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow);
	}

	void Actor::UnequipItem(RE::TESBoundObject* a_item, RE::ExtraDataList* a_extraData, std::uint32_t a_count, const RE::BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow, const RE::BGSEquipSlot* a_slotToReplace) {
		RE::ActorEquipManager::GetSingleton()->UnequipObject(this, a_item, a_extraData, a_count, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow, a_slotToReplace);
	}

	void Actor::SetOutfit(Outfit const& a_outfit) {
		EquipSequence seq;

		auto wornItems = get_worn_items(*this);
		auto seq1 = wornItems | std::views::filter(a_outfit.mask) | std::views::transform([](auto e) { e.count = -e.count; return e; });
		auto seq2 = a_outfit.items | std::views::filter(a_outfit.mask);
		auto isArmor = [](EquipParams const& e) { return e.item->formType == RE::FormType::Armor; };
		auto seq1armor = seq1 | std::views::filter(isArmor);
		auto seq2armor = seq2 | std::views::filter(isArmor);
		auto comp = [](EquipParams const& e1, EquipParams const& e2) { return e1.item == e2.item; };
		set_difference(seq1, seq2armor, std::back_inserter(seq), comp);
		set_difference(seq2, seq1armor, std::back_inserter(seq), comp);

		do_equip(*this, seq);

		auto& data = ActorData::Get(*this);
		std::lock_guard<std::mutex> lg(data.lock);
		data.equipHistory.insert(data.equipHistory.end(), seq.begin(), seq.end());
	}

	void Actor::ResetOutfit() {
		auto& data = ActorData::Get(*this);
		std::lock_guard<std::mutex> lg(data.lock);
		do_reverse_equip(*this, data.equipHistory);
		data.equipHistory.clear();
	}

	std::optional<Outfit> Actor::GetSleepOutfit() {
		auto actorBase = GetActorBase();

		if (!actorBase) {
			return std::nullopt;
		}

		auto& settings = Settings::Get();
		auto& actorSettings = settings.actors.contains(actorBase->formID) ? settings.actors[actorBase->formID] : settings.actorDefault;

		if (actorSettings.useVanillaSleepOutfit) {
			if (!actorBase->sleepOutfit) {
				return std::nullopt;
			}

			return *actorBase->sleepOutfit;
		} else {
			if (actorSettings.sleepOutfit.empty() || !settings.outfits.contains(actorSettings.sleepOutfit)) {
				return std::nullopt;
			}

			return settings.outfits[actorSettings.sleepOutfit];
		}
	}

	void Actor::UpdateOutfit() {
		if (IsInCombat()) {
			return;
		}

		auto actorBase = GetActorBase();

		if (!actorBase) {
			return;
		}

		auto& settings = Settings::Get();
		auto& actorSettigns = settings.actors.contains(actorBase->formID) ? settings.actors[actorBase->formID] : settings.actorDefault;
		auto& conditions = actorSettigns.sleepOutfitEquipConditions;

		if (!conditions(*this)) {
			ResetOutfit();
			return;
		}

		auto outfit = GetSleepOutfit();

		if (!outfit) {
			ResetOutfit();
			return;
		}

		SetOutfit(*outfit);
	}
}