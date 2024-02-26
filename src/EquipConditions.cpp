#include "EquipConditions.h"
#include "Actor.h"
#include "formtostr.h"

namespace Gotobed
{
	bool EquipConditions::operator()(Actor& a_actor) {
		if (a_actor.actorState1.sitSleepState < RE::SIT_SLEEP_STATE::kWantToSleep || a_actor.actorState1.sitSleepState >  RE::SIT_SLEEP_STATE::kWantToWake) {
			return false;
		}

		if (!locationType.empty()) {
			auto location = a_actor.GetCurrentLocation();

			if (!location) {
				return false;
			}

			auto result = std::ranges::find_if(locationType, [&](auto const& type) {
				return location->HasKeyword(type);
			});
			
			if (result == locationType.end()) {
				return false;
			}
		}

		return true;
	}

	void to_json(json& a_json, EquipConditions const& a_cond) {
		auto j = json::array();

		for (auto& type: a_cond.locationType) {
			auto typestr = to_str<RE::TESForm*>(type);

			if (!typestr.empty()) {
				j.push_back(typestr);
			}
		}

		a_json["locationType"] = j;
	}

	void from_json(json const& a_json, EquipConditions& a_cond) {
		for (auto& str: a_json.at("locationType")) {
			auto form = from_str<RE::TESForm*>(str);

			if (form && form->formType == RE::FormType::Keyword) {
				a_cond.locationType.push_back(static_cast<RE::BGSKeyword*>(form));
			}
		}
	}
}