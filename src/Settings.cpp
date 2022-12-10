#include "Settings.h"
#include "SimpleIni.h"

namespace Gotobed
{
	namespace
	{
		std::filesystem::path GetIniPath()
		{
			wchar_t buf[4096] = L"";

			std::uint32_t size = GetModuleFileNameW(NULL, buf, static_cast<DWORD>(std::size(buf)));

			if (size == 0 || size == std::size(buf)) {
				return "";
			}

			std::filesystem::path path{ buf };

			return path.replace_filename(L"Data\\SKSE\\Plugins\\gotobed.ini");
		}
	}

	Settings& Settings::Get()
	{
		static Settings settings;
		return settings;
	}

	void Settings::Read()
	{
		CSimpleIniA ini;
		auto path = GetIniPath();

		if (ini.LoadFile(path.c_str()) != SI_OK) {
			return;
		}

		sleepwear.vanillaSleepOutfit = ini.GetBoolValue("Sleepwear", "VanillaSleepOutfit", sleepwear.vanillaSleepOutfit);
		fixes.multipleMarkersReservation = ini.GetBoolValue("Fixes", "MultipleMarkersReservation", fixes.multipleMarkersReservation);
	}

	void Settings::Write()
	{
		CSimpleIniA ini;
		auto path = GetIniPath();

		ini.LoadFile(path.c_str());

		ini.SetBoolValue("Sleepwear", "VanillaSleepOutfit", sleepwear.vanillaSleepOutfit);
		ini.SetBoolValue("Fixes", "MultipleMarkersReservation", fixes.multipleMarkersReservation);

		ini.SaveFile(path.c_str());
	}
}