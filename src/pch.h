#pragma once

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"
#include <spdlog/sinks/basic_file_sink.h>

#define NOMINMAX
#define NOGDI
#include <windows.h>
#include "Detours/include/detours.h"

using namespace std::literals;

#include "version.h"

namespace stl
{
	template <class T>
	void write_thunk_call(std::uintptr_t a_src)
	{
		auto& trampoline = SKSE::GetTrampoline();
		SKSE::AllocTrampoline(14);

		if constexpr (std::is_member_pointer_v<decltype(&T::thunk)>) {
			T::func = trampoline.write_call<5>(a_src, &T::thunk);
		} else {
			T::func = trampoline.write_call<5>(a_src, T::thunk);
		}
	}
}