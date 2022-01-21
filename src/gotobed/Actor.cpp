#include "Actor.h"
#include "Outfit.h"

namespace Gotobed
{
	std::int32_t Actor::GetItemCount(RE::TESBoundObject* a_item) const
	{
		if (!a_item) {
			return 0;
		}

		auto container = static_cast<const RE::TESContainer*>(GetActorBase());

		if (!container) {
			return 0;
		}

		std::int32_t count = 0;

		for (std::uint32_t i = 0; i < container->numContainerObjects; i++) {
			auto entry = container->containerObjects[i];
			if (entry && entry->obj == a_item) {
				count = entry->count;
				break;
			}
		}

		auto containerChanges = extraList.GetByType<RE::ExtraContainerChanges>();

		if (containerChanges && containerChanges->changes && containerChanges->changes->entryList) {
			for (auto& entry : *containerChanges->changes->entryList) {
				if (entry && entry->object == a_item) {
					count += entry->countDelta;
					break;
				}
			}
		}

		return count;
	}

	bool Actor::IsEquipped(RE::TESBoundObject* a_item) const
	{
		if (!a_item) {
			return false;
		}

		auto containerChanges = extraList.GetByType<RE::ExtraContainerChanges>();

		if (!containerChanges || !containerChanges->changes || !containerChanges->changes->entryList) {
			return false;
		}

		for (auto& entry : *containerChanges->changes->entryList) {
			if (entry && entry->object == a_item) {
				if (entry->extraLists) {
					for (auto& extraList : *entry->extraLists) {
						if (extraList && (extraList->HasType<RE::ExtraWorn>() || extraList->HasType<RE::ExtraWornLeft>())) {
							return true;
						}
					}
				}
				break;
			}
		}

		return false;
	}

	EquipList Actor::GetEquippedItems() const
	{
		EquipList list;

		auto containerChanges = extraList.GetByType<RE::ExtraContainerChanges>();
		auto leftHandSlot = RE::BGSDefaultObjectManager::GetSingleton()->GetObject<RE::BGSEquipSlot>(RE::DEFAULT_OBJECTS::kLeftHandEquip);
		auto rightHandSlot = RE::BGSDefaultObjectManager::GetSingleton()->GetObject<RE::BGSEquipSlot>(RE::DEFAULT_OBJECTS::kRightHandEquip);

		if (containerChanges && containerChanges->changes && containerChanges->changes->entryList) {
			for (auto& entry : *containerChanges->changes->entryList) {
				if (entry && entry->object && entry->extraLists) {
					for (auto& extraList : *entry->extraLists) {
						if (extraList && (extraList->HasType<RE::ExtraWorn>() || extraList->HasType<RE::ExtraWornLeft>())) {
							auto count = entry->object->formType == RE::FormType::Ammo ? static_cast<std::uint32_t>(extraList->GetCount()) : 1;
							auto slot = entry->object->formType == RE::FormType::Weapon ? (extraList->HasType<RE::ExtraWornLeft>() ? leftHandSlot : rightHandSlot) : nullptr;
							list.entries.push_back({ entry->object, count, slot });
						}
					}
				}
			}
		}

		return list;
	}

	void Actor::EquipItems(const EquipList& a_list)
	{
		for (const auto& entry : a_list.entries) {
			if (entry.item) {
				if (entry.item->formType == RE::FormType::Weapon) {
					if (IsEquipped(entry.item) && GetItemCount(entry.item) == 1) {
						RE::ActorEquipManager::GetSingleton()->UnequipObject(this, entry.item);
					}
				}

				RE::ActorEquipManager::GetSingleton()->EquipObject(this, entry.item, nullptr, entry.count, entry.slot);
			}
		}
	}

	void Actor::UnequipItems(const EquipList& a_list)
	{
		for (const auto& entry : a_list.entries) {
			if (entry.item) {
				RE::ActorEquipManager::GetSingleton()->UnequipObject(this, entry.item, nullptr, entry.count, entry.slot);
			}
		}
	}

	template<class Pred>
	void Actor::EquipItemsIf(const EquipList& a_list, Pred a_pred)
	{
		for (const auto& entry : a_list.entries) {
			if (entry.item && a_pred(entry)) {
				if (entry.item->formType == RE::FormType::Weapon) {
					if (IsEquipped(entry.item) && GetItemCount(entry.item) == 1) {
						RE::ActorEquipManager::GetSingleton()->UnequipObject(this, entry.item);
					}
				}

				RE::ActorEquipManager::GetSingleton()->EquipObject(this, entry.item, nullptr, entry.count, entry.slot);
			}
		}
	}

	template<class Pred>
	void Actor::UnequipItemsIf(const EquipList& a_list, Pred a_pred)
	{
		for (const auto& entry : a_list.entries) {
			if (entry.item && a_pred(entry)) {
				RE::ActorEquipManager::GetSingleton()->UnequipObject(this, entry.item, nullptr, entry.count, entry.slot);
			}
		}
	}

	void Actor::EquipOutfit(const Outfit& a_outfit)
	{
		auto player = RE::PlayerCharacter::GetSingleton();

		if (static_cast<RE::Actor*>(this) == player) {
			if (a_outfit.mask.lhand) {
				player->lastOneHandItems[0] = nullptr;
			}
			if (a_outfit.mask.rhand) {
				player->lastOneHandItems[1] = nullptr;
			}
		}

		UnequipItemsIf(GetEquippedItems(), std::not_fn(~a_outfit.mask));
		EquipItemsIf(a_outfit.items, a_outfit.mask);
	}
}