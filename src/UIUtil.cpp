#include "UIUtil.h"
#include "UIFuncs.h"

namespace Gotobed::UIUtil
{
	void ShowSleepWaitMenu(RE::StaticFunctionTag*, bool a_sleep) {
		UIFuncs::ShowSleepWaitMenu(a_sleep);
	}

	void Register() {
		SKSE::GetPapyrusInterface()->Register([](RE::BSScript::IVirtualMachine* a_vm) {
			a_vm->RegisterFunction("ShowSleepWaitMenu", "GTB_UIUtil", ShowSleepWaitMenu);
			return true;
		});
	}
}