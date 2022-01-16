#pragma once

namespace Gotobed
{
	struct MenuOpenHandler : public RE::MenuOpenHandler
	{
		bool	ProcessButton_Original(RE::ButtonEvent* a_event);
		bool	ProcessButton_Hook(RE::ButtonEvent* a_event);
	};

	namespace MenuOpenHandlerNS
	{
		void	Init();
	}
}