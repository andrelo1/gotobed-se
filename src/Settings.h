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
			std::uint32_t	sleep{0};
			std::uint32_t	sleepMod{0};
			std::uint32_t	serveTime{0};
			std::uint32_t	serveTimeMod{0};
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