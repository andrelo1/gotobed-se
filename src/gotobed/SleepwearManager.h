#pragma once

#include "Outfit.h"

namespace Gotobed
{
	class SleepwearManager
	{
	public:
		class EquipConditions
		{
		public:
			EquipConditions() = default;
			EquipConditions(std::int32_t a_obj);

			bool	operator()(RE::Actor* a_actor) const;

			std::vector<RE::TESForm*>	locType;
		};

		static SleepwearManager&	Get();

		bool						IsSleepOutfitEnabled(RE::Actor* a_actor);
		bool						IsSleepOutfitEquipped(RE::Actor* a_actor);
		std::optional<Outfit>		GetSleepOutfit(RE::Actor* a_actor);
		void						EquipSleepOutfit(RE::Actor* a_actor);
		void						UnequipSleepOutfit(RE::Actor* a_actor);
		void						UpdateOutfit(RE::Actor* a_actor);
	};
}