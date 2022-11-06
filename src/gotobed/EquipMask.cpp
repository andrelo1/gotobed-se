#include "EquipMask.h"
#include "JCApi.h"

namespace Gotobed
{
	bool EquipMask::operator()(EquipParams const& a_params) const
	{
		if (!a_params.item) {
			return false;
		}

		switch (a_params.item->GetFormType()) {
			case RE::FormType::Armor: {
				auto slotMask = static_cast<std::uint32_t>(static_cast<RE::TESObjectARMO*>(a_params.item)->GetSlotMask());

				if (!slotMask) {
					break;
				}

				return (armor & slotMask) != 0;
			}
			case RE::FormType::Ammo: {
				return ammo;
			}
			case RE::FormType::Weapon: {
				auto dom = RE::BGSDefaultObjectManager::GetSingleton();
				auto lhandSlot = dom->GetObject<RE::BGSEquipSlot>(RE::DEFAULT_OBJECTS::kLeftHandEquip);
				auto rhandSlot = dom->GetObject<RE::BGSEquipSlot>(RE::DEFAULT_OBJECTS::kRightHandEquip);
				return a_params.slot == lhandSlot && lhand || a_params.slot == rhandSlot && rhand;
			}
		}

		return misc;
	}

	template<>
	EquipMask FromJC(jc::Handle a_jcmask)
	{
		EquipMask mask;

		if (a_jcmask == jc::Handle::Null) {
			return mask;
		}

		mask.armor = jc::JMap::getInt(a_jcmask, "armor", 0xFFFFFFFF);
		mask.lhand = jc::JMap::getInt(a_jcmask, "lhand", 1);
		mask.rhand = jc::JMap::getInt(a_jcmask, "rhand", 1);
		mask.ammo = jc::JMap::getInt(a_jcmask, "ammo", 1);
		mask.misc = jc::JMap::getInt(a_jcmask, "misc", 1);

		return mask;
	}

	template<>
	jc::Handle ToJC(EquipMask const& a_mask)
	{
		auto jcmask = jc::JMap::object();

		jc::JMap::setInt(jcmask, "armor", a_mask.armor);
		jc::JMap::setInt(jcmask, "lhand", a_mask.lhand);
		jc::JMap::setInt(jcmask, "rhand", a_mask.rhand);
		jc::JMap::setInt(jcmask, "ammo", a_mask.ammo);
		jc::JMap::setInt(jcmask, "misc", a_mask.misc);

		return jcmask;
	}
}