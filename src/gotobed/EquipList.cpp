#include "EquipList.h"

namespace Gotobed
{
	EquipList::EquipList(std::int32_t a_obj)
	{
		if (a_obj) {
			auto domain = jc::domain::get();
			auto count = jc::JArray::count(domain, a_obj);

			for (int i = 0; i < count; ++i) {
				auto entry = jc::JArray::getObj(domain, a_obj, i);
				auto item = jc::JMap::getForm(domain, entry, "item");

				if (!item || !item->IsBoundObject()) {
					continue;
				}

				auto count = jc::JMap::getInt(domain, entry, "count", 1);
				auto slot = jc::JMap::getForm(domain, entry, "slot");

				entries.push_back({ static_cast<RE::TESBoundObject*>(item), static_cast<std::uint32_t>(count), slot && slot->formType == RE::FormType::EquipSlot ? static_cast<RE::BGSEquipSlot*>(slot) : nullptr });
			}
		}
	}

	EquipList::operator std::int32_t() const
	{
		auto domain = jc::domain::get();
		auto listObj = jc::JArray::object(domain);

		for (auto& entry : entries) {
			auto entryObj = jc::JMap::object(domain);
			jc::JMap::setForm(domain, entryObj, "item", entry.item);
			jc::JMap::setInt(domain, entryObj, "count", entry.count);
			jc::JMap::setForm(domain, entryObj, "slot", entry.slot);
			jc::JArray::addObj(domain, listObj, entryObj);
		}

		return listObj;
	}
}