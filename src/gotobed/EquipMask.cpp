#include "EquipMask.h"

namespace Gotobed
{
	EquipMask::EquipMask(std::uint32_t a_armor, bool a_lhand, bool a_rhand, bool a_ammo, bool a_misc):
		armor(a_armor),
		lhand(a_lhand),
		rhand(a_rhand),
		ammo(a_ammo),
		misc(a_misc)
	{
	}

	EquipMask::EquipMask(std::int32_t a_obj)
	{
		if (a_obj) {
			auto domain = jc::domain::get();
			armor = jc::JMap::getInt(domain, a_obj, "armor", 0xFFFFFFFF);
			lhand = jc::JMap::getInt(domain, a_obj, "lhand", 1);
			rhand = jc::JMap::getInt(domain, a_obj, "rhand", 1);
			ammo = jc::JMap::getInt(domain, a_obj, "ammo", 1);
			misc = jc::JMap::getInt(domain, a_obj, "misc", 1);
		}
	}

	bool EquipMask::operator()(const EquipList::Entry& a_entry) const
	{
		if (!a_entry.item) {
			return false;
		}

		switch (a_entry.item->formType.get()) {
			case RE::FormType::Armor: {
				auto slotMask = static_cast<std::uint32_t>(static_cast<RE::TESObjectARMO*>(a_entry.item)->GetSlotMask());
				return (slotMask || misc) && (slotMask & armor) == slotMask;
			};
			case RE::FormType::Ammo: {
				return ammo;
			};
			case RE::FormType::Weapon: {
				auto dom = RE::BGSDefaultObjectManager::GetSingleton();
				auto lhandSlot = dom->GetObject<RE::BGSEquipSlot>(RE::DEFAULT_OBJECTS::kLeftHandEquip);
				auto rhandSlot = dom->GetObject<RE::BGSEquipSlot>(RE::DEFAULT_OBJECTS::kRightHandEquip);
				return a_entry.slot == lhandSlot && lhand || a_entry.slot == rhandSlot && rhand;
			};
		}

		return misc;
	}

	EquipMask EquipMask::operator~() const
	{
		return { ~armor, !lhand, !rhand, !ammo, !misc };
	}

	EquipMask::operator std::int32_t() const
	{
		auto domain = jc::domain::get();
		auto maskObj = jc::JMap::object(domain);
		jc::JMap::setInt(domain, maskObj, "armor", armor);
		jc::JMap::setInt(domain, maskObj, "lhand", lhand);
		jc::JMap::setInt(domain, maskObj, "rhand", rhand);
		jc::JMap::setInt(domain, maskObj, "ammo", ammo);
		jc::JMap::setInt(domain, maskObj, "misc", misc);

		return maskObj;
	}
}