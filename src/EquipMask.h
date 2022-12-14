#pragma once

#include "EquipSequence.h"
#include "JCTypes.h"

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

	template<class T>
	T FromJC(jc::Handle);
	template<>
	EquipMask FromJC(jc::Handle a_jcmask);

	template<class T>
	jc::Handle ToJC(T const&);
	template<>
	jc::Handle ToJC(EquipMask const& a_mask);
}