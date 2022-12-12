#pragma once

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"

#define NOMINMAX
#define NOGDI
#include <windows.h>
#include "detours/detours.h"

#include "nlohmann/json.hpp"
using json = nlohmann::json;

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