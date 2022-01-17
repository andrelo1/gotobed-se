#pragma once

#include "EquipList.h"

namespace Gotobed
{
	struct EquipMask
	{
		EquipMask() = default;
		EquipMask(std::uint32_t a_armor, bool a_lhand, bool a_rhand, bool a_ammo, bool a_misc);
		EquipMask(std::int32_t a_obj);

		operator std::int32_t() const;

		bool		operator()(const EquipList::Entry& a_entry) const;
		EquipMask	operator~() const;

		std::uint32_t	armor{ 0xFFFFFFFF };
		bool			lhand{ true };
		bool			rhand{ true };
		bool			ammo{ true };
		bool			misc{ true };
	};
}