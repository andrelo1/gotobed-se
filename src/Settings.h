#pragma once

namespace Gotobed
{
	struct Settings
	{
		struct Sleepwear
		{
			bool	vanillaSleepOutfit{ true };
		};

		struct Fixes
		{
			bool	multipleMarkersReservation{ true };
		};

		static Settings&	Get();

		void	Read();
		void	Write();

		Sleepwear	sleepwear;
		Fixes		fixes;
	};
}