#pragma once

namespace Gotobed
{
	struct MenuOpenHandler : public RE::MenuOpenHandler
	{
		bool	ProcessButtonOrig(RE::ButtonEvent* a_event);
		bool	ProcessButtonHook(RE::ButtonEvent* a_event);
		bool	OnWaitButtonDown();

		static void	Init();
	};
}