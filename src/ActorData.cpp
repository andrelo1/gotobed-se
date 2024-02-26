#include "ActorData.h"
#include "SerializationStream.h"
#include "formtostr.h"

namespace Gotobed {
	ActorData::ActorData(ActorData const& a_data):
		equipHistory(a_data.equipHistory)
	{}

	ActorData::ActorData(ActorData&& a_data):
		equipHistory(std::move(a_data.equipHistory))
	{}

	ActorData& ActorData::operator=(ActorData const& a_data) {
		equipHistory = a_data.equipHistory;
		return *this;
	}

	ActorData& ActorData::operator=(ActorData&& a_data) {
		equipHistory = std::move(a_data.equipHistory);
		return *this;
	}

	ActorData& ActorData::Get(Actor& a_actor) {
		return GetStorage()[a_actor.formID];
	}

	void ActorData::Save(SKSE::SerializationInterface& a_intfc) {
		if (!a_intfc.OpenRecord('ACTD', 1)) {
			return;
		}

		try {
			SKSE::OSerializationStream str(a_intfc);
			json j = GetStorage();
			str << j << std::flush;
		} catch (json::exception& ex) {
			spdlog::error("error writing save data: {}", ex.what());
		}
	}

	bool ActorData::Load(SKSE::SerializationInterface& a_intfc, std::uint32_t a_type, std::uint32_t a_version, std::uint32_t a_length) {
		if (a_type != 'ACTD') {
			return false;
		}

		try {
			SKSE::ISerializationStream str(a_intfc);
			json j;
			str >> j;
			GetStorage() = j;
		} catch(json::exception& ex) {
			spdlog::error("error reading save data: {}", ex.what());
		}

		return true;
	}

	ActorData::Storage& ActorData::GetStorage() {
		static Storage storage;
		return storage;
	}

	void to_json(json& a_json, ActorData const& a_data) {
		a_json["equipHistory"] = a_data.equipHistory;
	}

	void from_json(json const& a_json, ActorData& a_data) {
		a_json.at("equipHistory").get_to(a_data.equipHistory);
	}

	void to_json(json& a_json, ActorData::Storage const& a_storage) {
		for (auto& [id, data]: a_storage) {
			if (data.equipHistory.empty()) {
				continue;
			}

			auto idstr = to_str<RE::FormID>(id);
			if (!idstr.empty()) {
				const std::lock_guard<std::mutex> lg(data.lock);
				a_json[idstr] = data;
			}
		}
	}

	void from_json(json const& a_json, ActorData::Storage& a_storage) {
		for (auto& [idstr, data]: a_json.items()) {
			auto id = from_str<RE::FormID>(idstr);
			if (id != 0) {
				const std::lock_guard<std::mutex> lg(a_storage[id].lock);
				a_storage[id] = std::move(data.get<ActorData>());
			}
		}
	}
}