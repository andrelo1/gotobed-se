#include "EquipMask.h"

namespace Gotobed
{
	bool EquipMask::operator()(EquipParams const& a_params) const {
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

	void to_json(json& a_json, EquipMask const& a_mask) {
		a_json["armor"] = a_mask.armor;
		a_json["lhand"] = a_mask.lhand;
		a_json["rhand"] = a_mask.rhand;
		a_json["ammo"] = a_mask.ammo;
		a_json["misc"] = a_mask.misc;
	}

	void from_json(json const& a_json, EquipMask& a_mask) {
		a_json.at("armor").get_to(a_mask.armor);
		a_json.at("lhand").get_to(a_mask.lhand);
		a_json.at("rhand").get_to(a_mask.rhand);
		a_json.at("ammo").get_to(a_mask.ammo);
		a_json.at("misc").get_to(a_mask.misc);
	}
}