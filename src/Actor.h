#pragma once

#include "Outfit.h"

namespace Gotobed
{
	class Actor : public RE::Actor
	{
	public:
		RE::BGSLocation*		GetCurrentLocation();
		void					EquipItem(RE::TESBoundObject* a_item, RE::ExtraDataList* a_extraData = nullptr, std::uint32_t a_count = 1, const RE::BGSEquipSlot* a_slot = nullptr, bool a_queueEquip = true, bool a_forceEquip = false, bool a_playSounds = true, bool a_applyNow = false);
		void					UnequipItem(RE::TESBoundObject* a_item, RE::ExtraDataList* a_extraData = nullptr, std::uint32_t a_count = 1, const RE::BGSEquipSlot* a_slot = nullptr, bool a_queueEquip = true, bool a_forceEquip = false, bool a_playSounds = true, bool a_applyNow = false, const RE::BGSEquipSlot* a_slotToReplace = nullptr);
		void					SetOutfit(Outfit const& a_outfit);
		void					ResetOutfit();
		std::optional<Outfit>	GetSleepOutfit();
		void					UpdateOutfit();
	};
}