#include "UIUtilPapyrus.h"
#include "UIUtil.h"

namespace Gotobed::UIUtilPapyrus
{
	void ShowSleepWaitMenu(RE::StaticFunctionTag*, bool a_sleep)
	{
		UIUtil::ShowSleepWaitMenu(a_sleep);
	}

	void Register()
	{
		SKSE::GetPapyrusInterface()->Register([](RE::BSScript::IVirtualMachine* a_vm) {
			a_vm->RegisterFunction("ShowSleepWaitMenu", "GTB_UIUtil", ShowSleepWaitMenu);
			return true;
		});
	}
}