#include "EquipSequence.h"
#include "JCApi.h"

namespace Gotobed
{
	template<>
	EquipParams FromJC(jc::Handle a_jcparams)
	{
		EquipParams params;

		if (a_jcparams != jc::Handle::Null) {
			auto item = jc::JMap::getForm(a_jcparams, "item");
			params.item = item && item->IsBoundObject() ? static_cast<RE::TESBoundObject*>(item) : nullptr;
			params.count = jc::JMap::getInt(a_jcparams, "count", 1);
			auto slot = jc::JMap::getForm(a_jcparams, "slot");
			params.slot = slot && slot->formType == RE::FormType::EquipSlot ? static_cast<RE::BGSEquipSlot*>(slot) : nullptr;
		}

		return params;
	}

	template<>
	jc::Handle ToJC(EquipParams const& a_params)
	{
		auto jcparams = jc::JMap::object();

		jc::JMap::setForm(jcparams, "item", a_params.item);
		jc::JMap::setInt(jcparams, "count", a_params.count);
		jc::JMap::setForm(jcparams, "slot", a_params.slot);

		return jcparams;
	}

	template<>
	EquipSequence FromJC(jc::Handle a_jcseq)
	{
		EquipSequence seq;

		if (a_jcseq != jc::Handle::Null) {
			auto count = jc::JArray::count(a_jcseq);

			for (int i = 0; i < count; ++i) {
				auto params = FromJC<EquipParams>(jc::JArray::getObj(a_jcseq, i));

				if (!params.item) {
					continue;
				}

				seq.push_back(std::move(params));
			}
		}

		return seq;
	}

	template<>
	jc::Handle ToJC(EquipSequence const& a_seq)
	{
		auto jcseq = jc::JArray::object();

		for (auto const& e : a_seq) {
			jc::JArray::addObj(jcseq, ToJC(e));
		}

		return jcseq;
	}
}