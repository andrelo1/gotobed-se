#pragma once

#include "EquipSequence.h"
#include "EquipMask.h"

namespace Gotobed
{
	struct Outfit
	{
		Outfit() = default;
		Outfit(RE::BGSOutfit const& a_outfit);

		std::string		name;
		EquipSequence	items;
		EquipMask		mask;
	};

	void to_json(json& a_json, Outfit const& a_outfit);
	void from_json(json const& a_json, Outfit& a_outfit);
}