#include "Outfit.h"
#include "JCApi.h"

namespace Gotobed
{
	Outfit::Outfit(RE::BGSOutfit const& a_outfit) {
		for (auto& item : a_outfit.outfitItems) {
			if (item && item->IsBoundObject()) {
				items.push_back({ static_cast<RE::TESBoundObject*>(item), 1, nullptr });
			}
		}
	}

	template<>
	Outfit FromJC(jc::Handle a_jcoutfit) {
		Outfit outfit;

		if (a_jcoutfit != jc::Handle::Null) {
			outfit.name = jc::JMap::getStr(a_jcoutfit, "name");
			outfit.items = FromJC<EquipSequence>(jc::JMap::getObj(a_jcoutfit, "items"));
			outfit.mask = FromJC<EquipMask>(jc::JMap::getObj(a_jcoutfit, "mask"));
		}

		return outfit;
	}

	template<>
	jc::Handle ToJC(Outfit const& a_outfit) {
		auto jcoutfit = jc::JMap::object();

		jc::JMap::setStr(jcoutfit, "name", a_outfit.name);
		jc::JMap::setObj(jcoutfit, "items", ToJC(a_outfit.items));
		jc::JMap::setObj(jcoutfit, "mask", ToJC(a_outfit.mask));

		return jcoutfit;
	}
}