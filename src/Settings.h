#pragma once

#include "Outfit.h"
#include "EquipConditions.h"

namespace Gotobed
{
	struct Settings
	{
		struct Fixes
		{
			bool	multipleMarkersReservation{true};
		};

		struct Keys
		{
			std::int32_t	sleep{-1};
			std::int32_t	sleepMod{-1};
			std::int32_t	serveTime{-1};
			std::int32_t	serveTimeMod{-1};
		};

		using Outfits = std::unordered_map<std::string, Outfit>;

		struct Actor {
			std::string		sleepOutfit;
			bool			useVanillaSleepOutfit{true};
			EquipConditions	sleepOutfitEquipConditions;
		};

		using Actors = std::unordered_map<RE::FormID, Actor>;

		static Settings&	Get();

		void	Read();
		void	Write();

		Fixes		fixes;
		Keys		keys;
		Outfits		outfits;
		Actors		actors;
		Actor		actorDefault;
	};

	void to_json(json& a_json, Settings::Fixes const& a_fixes);
	void from_json(json const& a_json, Settings::Fixes& a_fixes);

	void to_json(json& a_json, Settings::Keys const& a_keys);
	void from_json(json const& a_json, Settings::Keys& a_keys);

	void to_json(json& a_json, Settings::Actor const& a_actor);
	void from_json(json const& a_json, Settings::Actor& a_actor);

	void to_json(json& a_json, Settings const& a_settings);
	void from_json(json const& a_json, Settings& a_settings);
}