#include "EquipSequence.h"
#include "formtostr.h"

namespace Gotobed
{
	void to_json(json& a_json, EquipParams const& a_params) {
		a_json["item"] = to_str<RE::TESForm*>(a_params.item);
		a_json["count"] = a_params.count;
		a_json["slot"] = to_str<RE::TESForm*>(a_params.slot);
	}

	void from_json(json const& a_json, EquipParams& a_params) {
		{
			auto str = a_json.at("item").get<std::string>();
			auto form = from_str<RE::TESForm*>(str);
			a_params.item = form && form->IsBoundObject() ? static_cast<RE::TESBoundObject*>(form) : nullptr;
		}

		a_params.count = a_json.at("count").get<std::int32_t>();

		{
			auto str = a_json.at("slot").get<std::string>();
			auto form = from_str<RE::TESForm*>(str);
			a_params.slot = form && form->formType == RE::FormType::EquipSlot ? static_cast<RE::BGSEquipSlot*>(form) : nullptr;
		}
	}
}