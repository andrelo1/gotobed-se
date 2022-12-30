#pragma once

namespace Gotobed
{
	struct MenuOpenHandler : public RE::MenuOpenHandler
	{
		bool	CanProcessHook(RE::InputEvent* a_event);
		bool	ProcessButtonHook(RE::ButtonEvent* a_event);
		bool	OnSleepButtonDown();
		bool	OnServeTimeButtonDown();

		static void	InstallHooks();
	};
}