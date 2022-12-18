#pragma once

namespace Gotobed
{
	struct MenuOpenHandler : public RE::MenuOpenHandler
	{
		bool	ProcessButtonHook(RE::ButtonEvent* a_event);
		bool	OnWaitButtonDown();

		static void	InstallHooks();
	};
}