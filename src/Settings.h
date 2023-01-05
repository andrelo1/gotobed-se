#pragma once

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

		static Settings&	Get();

		void	Read();
		void	Write();

		bool	vanillaSleepOutfit{true};
		Fixes	fixes;
		Keys	keys;
	};

	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Settings::Fixes, multipleMarkersReservation)
	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Settings::Keys, sleep, sleepMod, serveTime, serveTimeMod)
	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Settings, vanillaSleepOutfit, fixes, keys)
}