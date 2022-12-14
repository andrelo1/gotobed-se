#include "Settings.h"

namespace Gotobed
{
	namespace detail
	{
		std::filesystem::path GetSettingsPath() {
			std::vector<wchar_t> buf(4096);
			auto size = GetModuleFileNameW(nullptr, &buf[0], buf.size());

			if (size == 0 || size == buf.size()) {
				spdlog::error("error getting settings path: {}", GetLastError());
				return "";
			}

			return std::filesystem::path(&buf[0]).replace_filename(L"Data\\SKSE\\Plugins\\gotobed\\settings.json");
		}
	}

	Settings& Settings::Get() {
		static Settings settings;
		return settings;
	}

	void Settings::Read() {
		try {
			std::ifstream f(detail::GetSettingsPath());
			*this = json::parse(f).get<Settings>();
		} catch (json::exception& e) {
			spdlog::error("error reading settings: {}", e.what());
		}
	}

	void Settings::Write() {
		try {
			std::ofstream f(detail::GetSettingsPath());
			f << std::setw(4) << json(*this);
		} catch (json::exception& e) {
			spdlog::error("error writing settings: {}", e.what());
		}
	}
}