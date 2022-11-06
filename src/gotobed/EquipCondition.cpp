#include "EquipConditions.h"
#include "Actor.h"
#include "JCApi.h"

namespace Gotobed
{
	bool EquipConditions::operator()(Actor& a_actor)
	{
		if (a_actor.actorState1.sitSleepState < RE::SIT_SLEEP_STATE::kWantToSleep || a_actor.actorState1.sitSleepState >  RE::SIT_SLEEP_STATE::kWantToWake) {
			return false;
		}

		if (!locType.empty()) {

			auto location = a_actor.GetCurrentLocation();

			if (!location) {
				return false;
			}

			auto result = std::ranges::find_if(locType, [&](auto const& type) {
				return location->HasKeyword(type);
			});
			
			if (result == locType.end()) {
				return false;
			}
		}

		return true;
	}

	template<>
	EquipConditions FromJC(jc::Handle a_jcconditions)
	{
		EquipConditions conditions;

		if (a_jcconditions != jc::Handle::Null) {
			auto locType = jc::JMap::getObj(a_jcconditions, "locType");

			if (locType != jc::Handle::Null) {
				auto count = jc::JArray::count(locType);

				for (int i = 0; i < count; ++i) {
					auto type = jc::JArray::getForm(locType, i);
					if (type && type->formType == RE::FormType::Keyword) {
						conditions.locType.push_back(static_cast<RE::BGSKeyword*>(type));
					}
				}
			}
		}

		return conditions;
	}

	template<>
	jc::Handle ToJC(EquipConditions const& a_conditions)
	{
		auto jcconditions = jc::JMap::object();

		auto locType = jc::JArray::object();
		for (auto const& type : a_conditions.locType) {
			jc::JArray::addForm(locType, type);
		}

		jc::JMap::setObj(jcconditions, "locType", locType);

		return jcconditions;
	}
}