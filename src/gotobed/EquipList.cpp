#include "EquipList.h"
#include "JCApi.h"

namespace Gotobed
{
	EquipList::EquipList(std::int32_t a_obj)
	{
		if (a_obj) {
			auto count = jc::JArray::count(a_obj);

			for (int i = 0; i < count; ++i) {
				auto entry = jc::JArray::getObj(a_obj, i);
				auto item = jc::JMap::getForm(entry, "item");

				if (!item || !item->IsBoundObject()) {
					continue;
				}

				auto count = jc::JMap::getInt(entry, "count", 1);
				auto slot = jc::JMap::getForm(entry, "slot");

				entries.push_back({ static_cast<RE::TESBoundObject*>(item), static_cast<std::uint32_t>(count), slot && slot->formType == RE::FormType::EquipSlot ? static_cast<RE::BGSEquipSlot*>(slot) : nullptr });
			}
		}
	}

	EquipList::operator std::int32_t() const
	{
		auto listObj = jc::JArray::object();

		for (auto& entry : entries) {
			auto entryObj = jc::JMap::object();
			jc::JMap::setForm(entryObj, "item", entry.item);
			jc::JMap::setInt(entryObj, "count", entry.count);
			jc::JMap::setForm(entryObj, "slot", entry.slot);
			jc::JArray::addObj(listObj, entryObj);
		}

		return listObj;
	}
}