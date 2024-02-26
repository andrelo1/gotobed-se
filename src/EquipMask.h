#pragma once

#include "EquipSequence.h"

namespace Gotobed
{
	struct EquipMask
	{
		bool	operator()(EquipParams const& a_params) const;

		std::uint32_t	armor{0xFFFFFFFF};
		bool			lhand{true};
		bool			rhand{true};
		bool			ammo{true};
		bool			misc{true};
	};

	void to_json(json& a_json, EquipMask const& a_mask);
	void from_json(json const& a_json, EquipMask& a_mask);
}