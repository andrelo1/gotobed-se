#include "Outfit.h"

namespace Gotobed
{
	Outfit::Outfit(std::int32_t a_obj)
	{
		if (a_obj) {
			auto domain = jc::domain::get();
			name = jc::JMap::getStr(domain, a_obj, "name");
			items = jc::JMap::getObj(domain, a_obj, "items");
			mask = jc::JMap::getObj(domain, a_obj, "mask");
		}
	}

	Outfit::Outfit(EquipList&& a_list) : items(std::move(a_list))
	{
	}

	Outfit::Outfit(const RE::BGSOutfit& a_outfit)
	{
		for (auto& item : a_outfit.outfitItems) {
			if (item && item->IsBoundObject()) {
				items.entries.push_back({ static_cast<RE::TESBoundObject*>(item), 1, nullptr });
			}
		}
	}

	Outfit::operator std::int32_t() const
	{
		auto domain = jc::domain::get();
		auto outfitObj = jc::JMap::object(domain);
		jc::JMap::setStr(domain, outfitObj, "name", name);
		jc::JMap::setObj(domain, outfitObj, "items", items);
		jc::JMap::setObj(domain, outfitObj, "mask", mask);

		return outfitObj;
	}
}