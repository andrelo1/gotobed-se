#pragma once

namespace Gotobed
{
	struct Settings
	{
		struct Sleepwear
		{
			bool	vanillaSleepOutfit{true};
		};

		struct Fixes
		{
			bool	multipleMarkersReservation{true};
		};

		static Settings&	Get();

		void	Read();
		void	Write();

		Sleepwear	sleepwear;
		Fixes		fixes;
	};

	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Settings::Sleepwear, vanillaSleepOutfit)
	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Settings::Fixes, multipleMarkersReservation)
	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Settings, sleepwear, fixes)
}