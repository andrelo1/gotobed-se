#include "Outfit.h"
#include "JCApi.h"

namespace Gotobed
{
	Outfit::Outfit(std::int32_t a_obj)
	{
		if (a_obj) {
			name = jc::JMap::getStr(a_obj, "name");
			items = jc::JMap::getObj(a_obj, "items");
			mask = jc::JMap::getObj(a_obj, "mask");
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
		auto outfitObj = jc::JMap::object();
		jc::JMap::setStr(outfitObj, "name", name);
		jc::JMap::setObj(outfitObj, "items", items);
		jc::JMap::setObj(outfitObj, "mask", mask);

		return outfitObj;
	}
}