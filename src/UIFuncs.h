#pragma once

#include "Offsets.h"

namespace Gotobed::UIFuncs
{
	template<class... Args>
	bool ShowMessageBox(const char* a_msg, void (*a_callback)(std::uint8_t), std::uint8_t a_unk3, std::uint32_t a_unk4, std::uint32_t a_unk5, Args... a_args) {
		using func_t = decltype(&ShowMessageBox<Args...>);
		REL::Relocation<func_t> func{Offsets::ShowMessageBox};
		return func(a_msg, a_callback, a_unk3, a_unk4, a_unk5, a_args...);
	}

	void ShowSleepWaitMenu(bool a_sleep);
	void ShowServeSentenceQuestion();
}