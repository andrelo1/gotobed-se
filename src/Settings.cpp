#include "Settings.h"
#include "formtostr.h"

namespace Gotobed
{
	namespace
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
			std::ifstream f(GetSettingsPath());
			*this = json::parse(f).get<Settings>();
		} catch (json::exception& e) {
			spdlog::error("error reading settings: {}", e.what());
		}
	}

	void Settings::Write() {
		try {
			std::ofstream f(GetSettingsPath());
			f << std::setw(4) << json(*this);
		} catch (json::exception& e) {
			spdlog::error("error writing settings: {}", e.what());
		}
	}

	void to_json(json& a_json, Settings::Fixes const& a_fixes) {
		a_json["multipleMarkersReservation"] = a_fixes.multipleMarkersReservation;
	}

	void from_json(json const& a_json, Settings::Fixes& a_fixes) {
		a_json.at("multipleMarkersReservation").get_to(a_fixes.multipleMarkersReservation);
	}

	void to_json(json& a_json, Settings::Keys const& a_keys) {
		a_json["sleep"] = a_keys.sleep;
		a_json["sleepMod"] = a_keys.sleepMod;
		a_json["serveTime"] = a_keys.serveTime;
		a_json["serveTimeMod"] = a_keys.serveTimeMod;
	}

	void from_json(json const& a_json, Settings::Keys& a_keys) {
		a_json.at("sleep").get_to(a_keys.sleep);
		a_json.at("sleepMod").get_to(a_keys.sleepMod);
		a_json.at("serveTime").get_to(a_keys.serveTime);
		a_json.at("serveTimeMod").get_to(a_keys.serveTimeMod);
	}

	void to_json(json& a_json, Settings::Actor const& a_actor) {
		a_json["sleepOutfit"] = a_actor.sleepOutfit;
		a_json["useVanillaSleepOutfit"] = a_actor.useVanillaSleepOutfit;
		a_json["sleepOutfitEquipConditions"] = a_actor.sleepOutfitEquipConditions;
	}

	void from_json(json const& a_json, Settings::Actor& a_actor) {
		a_json.at("sleepOutfit").get_to(a_actor.sleepOutfit);
		a_json.at("useVanillaSleepOutfit").get_to(a_actor.useVanillaSleepOutfit);
		a_json.at("sleepOutfitEquipConditions").get_to(a_actor.sleepOutfitEquipConditions);
	}

	void to_json(json& a_json, Settings const& a_settings) {
		a_json["fixes"] = a_settings.fixes;
		a_json["keys"] = a_settings.keys;
		a_json["outfits"] = a_settings.outfits;

		{
			auto j = json::object();

			for (auto& [id, actor]: a_settings.actors) {
				auto idstr = to_str<RE::FormID>(id);

				if (!idstr.empty()) {
					j[idstr] = actor;
				}
			}

			a_json["actors"] = j;
		}

		a_json["actorDefault"] = a_settings.actorDefault;
	}

	void from_json(json const& a_json, Settings& a_settings) {
		a_json.at("fixes").get_to(a_settings.fixes);
		a_json.at("keys").get_to(a_settings.keys);
		a_json.at("outfits").get_to(a_settings.outfits);

		for (auto& [idstr, actor]: a_json.at("actors").items()) {
			auto id = from_str<RE::FormID>(idstr);

			if (id != 0) {
				a_settings.actors[id] = actor;
			}
		}

		a_json.at("actorDefault").get_to(a_settings.actorDefault);
	}
}