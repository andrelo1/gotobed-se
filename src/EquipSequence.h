#pragma once

#include "JCTypes.h"

namespace Gotobed
{
	struct EquipParams
	{
		RE::TESBoundObject*	item{ nullptr };
		std::int32_t		count{ 0 };
		RE::BGSEquipSlot*	slot{ nullptr };
	};

	using EquipSequence = std::vector<EquipParams>;

	template<class T>
	T FromJC(jc::Handle);
	template<>
	EquipParams FromJC(jc::Handle a_jcparams);
	template<>
	EquipSequence FromJC(jc::Handle a_jcseq);

	template<class T>
	jc::Handle ToJC(T const&);
	template<>
	jc::Handle ToJC(EquipParams const& a_params);
	template<>
	jc::Handle ToJC(EquipSequence const& a_seq);
}