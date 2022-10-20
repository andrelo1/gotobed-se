#include "UIUtil.h"
#include "Offsets.h"

namespace Gotobed::UIUtil
{
	namespace detail
	{
		void ShowSleepWaitMenu(bool a_sleep)
		{
			using func_t = decltype(&ShowSleepWaitMenu);
			REL::Relocation<func_t> func{ Offsets::ShowSleepWaitMenu };
			func(a_sleep);
		}
	}

	void ShowSleepWaitMenu(RE::StaticFunctionTag*, bool a_sleep)
	{
		detail::ShowSleepWaitMenu(a_sleep);
	}

	void Register()
	{
		SKSE::GetPapyrusInterface()->Register([](RE::BSScript::IVirtualMachine* a_vm) {
			a_vm->RegisterFunction("ShowSleepWaitMenu", "GTB_UIUtil", ShowSleepWaitMenu);
			return true;
		});
	}
}