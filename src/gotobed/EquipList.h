#pragma once

namespace Gotobed
{
	struct EquipList
	{
		struct Entry
		{
			RE::TESBoundObject*	item{ nullptr };
			std::uint32_t		count{ 0 };
			RE::BGSEquipSlot*	slot{ nullptr };
		};

		EquipList() = default;
		EquipList(const EquipList& a_list) = delete;
		EquipList(EquipList&& a_list) = default;
		EquipList(std::int32_t a_obj);

		EquipList& operator=(const EquipList& a_list) = delete;
		EquipList& operator=(EquipList&& a_list) = default;

		operator std::int32_t() const;

		std::vector<Entry>	entries;
	};
}