#include "Outfit.h"

namespace Gotobed
{
	Outfit::Outfit(RE::BGSOutfit const& a_outfit) {
		for (auto& item : a_outfit.outfitItems) {
			if (item && item->IsBoundObject()) {
				items.push_back({ static_cast<RE::TESBoundObject*>(item), 1, nullptr });
			}
		}
	}

	void to_json(json& a_json, Outfit const& a_outfit) {
		a_json["name"] = a_outfit.name;
		a_json["items"] = a_outfit.items;
		a_json["mask"] = a_outfit.mask;
	}

	void from_json(json const& a_json, Outfit& a_outfit) {
		a_json.at("name").get_to(a_outfit.name);
		a_json.at("items").get_to(a_outfit.items);
		a_json.at("mask").get_to(a_outfit.mask);
	}
}