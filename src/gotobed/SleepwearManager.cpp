#include "SleepwearManager.h"
#include "Offsets.h"
#include "Actor.h"
#include "JCApi.h"

namespace Gotobed
{
	namespace
	{
		RE::BGSLocation* GetCurrentLocation(RE::TESObjectREFR* a_this)
		{
			using func_t = decltype(&GetCurrentLocation);
			REL::Relocation<func_t> func{ Offsets::TESObjectREFR::GetCurrentLocation };
			return func(a_this);
		}
	}

	SleepwearManager::EquipConditions::EquipConditions(std::int32_t a_obj)
	{
		if (a_obj) {
			auto locTypeObj = jc::JMap::getObj(a_obj, "locType");

			if (locTypeObj) {
				auto count = jc::JArray::count(locTypeObj);

				for (int i = 0; i < count; ++i) {
					auto f = jc::JArray::getForm(locTypeObj, i);
					if (f) {
						locType.push_back(f);
					}
				}
			}
		}
	}

	bool SleepwearManager::EquipConditions::operator()(RE::Actor* a_actor) const
	{
		if (!a_actor) {
			return false;
		}

		if (locType.empty()) {
			return true;
		}

		auto location = GetCurrentLocation(a_actor);

		if (location) {
			for (auto& type : locType) {
				if (type->formType == RE::FormType::Keyword) {
					if (location->HasKeyword(static_cast<RE::BGSKeyword*>(type))) {
						return true;
					}
				}
			}
		}

		return false;
	}
	
	SleepwearManager& SleepwearManager::Get()
	{
		static SleepwearManager manager;
		return manager;
	}

	bool SleepwearManager::IsSleepOutfitEnabled(RE::Actor* a_actor)
	{
		return a_actor && true;
	}

	bool SleepwearManager::IsSleepOutfitEquipped(RE::Actor* a_actor)
	{
		return a_actor && jc::JFormDB::solveObj(a_actor, ".formdb.outfit");
	}

	std::optional<Outfit> SleepwearManager::GetSleepOutfit(RE::Actor* a_actor)
	{
		if (!a_actor) {
			return std::nullopt;
		}

		auto outfit = jc::JFormDB::solveObj(a_actor, ".formdb.preferences.sleepwear.outfit");

		if (outfit) {
			return outfit;
		}

		auto actorBase = a_actor->GetActorBase();

		if (actorBase && actorBase->sleepOutfit) {
			return *actorBase->sleepOutfit;
		}

		return std::nullopt;
	}

	void SleepwearManager::EquipSleepOutfit(RE::Actor* a_actor)
	{
		if (!a_actor || IsSleepOutfitEquipped(a_actor)) {
			return;
		}

		auto actor = static_cast<Actor*>(a_actor);

		auto sleepOutfit = GetSleepOutfit(a_actor);

		if (!sleepOutfit) {
			return;
		}

		Outfit outfit{ actor->GetEquippedItems() };

		jc::JFormDB::solveObjSetter(actor, ".formdb.outfit", outfit, true);

		actor->EquipOutfit(*sleepOutfit);
	}

	void SleepwearManager::UnequipSleepOutfit(RE::Actor* a_actor)
	{
		if (!a_actor || !IsSleepOutfitEquipped(a_actor)) {
			return;
		}

		auto actor = static_cast<Actor*>(a_actor);
		auto outfit = jc::JFormDB::solveObj(actor, ".formdb.outfit");

		if (!outfit) {
			return;
		}

		actor->EquipOutfit(outfit);

		jc::JFormDB::solveObjSetter(actor, ".formdb.outfit", 0);
	}

	void SleepwearManager::UpdateOutfit(RE::Actor* a_actor)
	{
		if (!a_actor) {
			return;
		}

		if (IsSleepOutfitEnabled(a_actor) && a_actor->actorState1.sitSleepState >= RE::SIT_SLEEP_STATE::kWantToSleep && a_actor->actorState1.sitSleepState <= RE::SIT_SLEEP_STATE::kWantToWake) {
			EquipConditions conditions{ jc::JFormDB::solveObj(a_actor, ".formdb.preferences.sleepwear.conditions") };

			if (conditions(a_actor)) {
				EquipSleepOutfit(a_actor);
			}
		} else {
			UnequipSleepOutfit(a_actor);
		}
	}
}