#pragma once

#include "EquipSequence.h"
#include "EquipMask.h"
#include "JCTypes.h"

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

	template<class T>
	T FromJC(jc::Handle);
	template<>
	Outfit FromJC(jc::Handle a_jcoutfit);

	template<class T>
	jc::Handle ToJC(T const&);
	template<>
	jc::Handle ToJC(Outfit const& a_outfit);
}