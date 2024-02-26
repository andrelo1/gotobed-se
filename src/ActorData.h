#pragma once

#include "Actor.h"

namespace Gotobed {
	class ActorData {
	public:
		using Storage = std::unordered_map<RE::FormID, ActorData>;

		static ActorData&	Get(Actor& a_actor);
		static void			Save(SKSE::SerializationInterface& a_intfc);
		static bool			Load(SKSE::SerializationInterface& a_intfc, std::uint32_t a_type, std::uint32_t a_version, std::uint32_t a_length);

		EquipSequence	equipHistory;

	private:
		static Storage&		GetStorage();
	};

	void to_json(json& a_json, ActorData const& a_data);
	void from_json(json const& a_json, ActorData& a_data);

	void to_json(json& a_json, ActorData::Storage const& a_storage);
	void from_json(json const& a_json, ActorData::Storage& a_storage);
}