#pragma once

namespace Gotobed
{
	struct MenuOpenHandler : public RE::MenuOpenHandler
	{
		bool	CanProcess_Orig(RE::InputEvent* a_event);
		bool	CanProcess_Hook(RE::InputEvent* a_event);
		bool	ProcessButton_Orig(RE::ButtonEvent* a_event);
		bool	ProcessButton_Hook(RE::ButtonEvent* a_event);
		bool	OnSleepButtonDown();
		bool	OnServeTimeButtonDown();

		static void	InstallHooks();
	};
}