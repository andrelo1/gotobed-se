#include "DiagUtil.h"
#include "JCApi.h"

namespace Gotobed::DiagUtil
{
	std::uint32_t GetJCApiStatus(RE::StaticFunctionTag*) {
		return jc::api::ready();
	}

	void Register() {
		SKSE::GetPapyrusInterface()->Register([](RE::BSScript::IVirtualMachine* a_vm) {
			a_vm->RegisterFunction("GetJCApiStatus", "GTB_DiagUtil", GetJCApiStatus);
			return true;
		});
	}
}