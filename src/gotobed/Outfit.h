#pragma once

#include "EquipList.h"
#include "EquipMask.h"

namespace Gotobed
{
	struct Outfit
	{
		Outfit() = default;
		Outfit(std::int32_t a_obj);
		Outfit(EquipList&& a_list);
		Outfit(const RE::BGSOutfit& a_outfit);

		operator std::int32_t() const;

		std::string	name;
		EquipList	items;
		EquipMask	mask;
	};
}