#include "DiagUtil.h"
#include "JCApi.h"

namespace Gotobed::DiagUtil
{
	std::int32_t GetJCApiStatus(RE::StaticFunctionTag*) {
		if (!jc::api::ready()) {
			return 1;
		}

		if (!jc::api::getDefaultDomain()) {
			return 2;
		}

		return 0;
	}

	void Register() {
		SKSE::GetPapyrusInterface()->Register([](RE::BSScript::IVirtualMachine* a_vm) {
			a_vm->RegisterFunction("GetJCApiStatus", "GTB_DiagUtil", GetJCApiStatus);
			return true;
		});
	}
}