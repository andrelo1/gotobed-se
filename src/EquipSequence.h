#pragma once

namespace Gotobed
{
	struct EquipParams
	{
		RE::TESBoundObject*	item{nullptr};
		std::int32_t		count{0};
		RE::BGSEquipSlot*	slot{nullptr};
	};

	using EquipSequence = std::vector<EquipParams>;

	void to_json(json& a_json, EquipParams const& a_params);
	void from_json(json const& a_json, EquipParams& a_params);
}