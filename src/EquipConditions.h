#pragma once

namespace Gotobed
{
	class Actor;

	struct EquipConditions
	{
		bool	operator()(Actor& a_actor);

		std::vector<RE::BGSKeyword*>	locationType;
	};

	void to_json(json& a_json, EquipConditions const& a_cond);
	void from_json(json const& a_json, EquipConditions& a_cond);
}