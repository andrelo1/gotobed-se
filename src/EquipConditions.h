#pragma once

#include "JCTypes.h"

namespace Gotobed
{
	class Actor;

	struct EquipConditions
	{
		bool	operator()(Actor& a_actor);

		std::vector<RE::BGSKeyword*>	locType;
	};

	template<class T>
	T FromJC(jc::Handle);
	template<>
	EquipConditions FromJC(jc::Handle a_jcconditions);

	template<class T>
	jc::Handle ToJC(T const&);
	template<>
	jc::Handle ToJC(EquipConditions const& a_conditions);
}