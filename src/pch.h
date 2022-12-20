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
	template<class To, class From>
	To unrestricted_cast(const From& a_src) {
		return reinterpret_cast<const To&>(a_src);
	}

	template<class F, class... Args>
	auto invoke_non_member(F a_func, Args... a_args) {
		using result_t = std::invoke_result_t<F, Args...>;
		using func_t = result_t(*)(Args...);
		auto func = unrestricted_cast<func_t>(a_func);
		return func(a_args...);
	}

	template<class F>
	struct HookData
	{
		template<class... Args>
		auto call_orig(Args... a_args) {
			// std::invoke doesn't work well if function is a member function of class derived from several base classes,
			// compiler uses some math to calculate _this pointer and gets wrong result
			// return std::invoke(orig, a_args...);
			return invoke_non_member(orig, a_args...);
		}

		F	hook{nullptr};
		F	orig{nullptr};
	};
	
	template<class T>
	std::uintptr_t write_detour(std::uintptr_t a_src, T a_dst) {
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&a_src), reinterpret_cast<PVOID&>(a_dst));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}

		return a_src;
	}

	template <class T>
	std::uintptr_t write_call(std::uintptr_t a_src, T a_dst) {
		auto& trampoline = SKSE::GetTrampoline();
		SKSE::AllocTrampoline(14);
		return trampoline.write_call<5>(a_src, unrestricted_cast<std::uintptr_t>(a_dst));
	}

	template<class F>
	void write_detour(std::uintptr_t a_src, HookData<F>& a_hook) {
		auto orig = write_detour(a_src, a_hook.hook);
		a_hook.orig = unrestricted_cast<F>(orig);
	}

	template<class F>
	void write_thunk(std::uintptr_t a_src, HookData<F>& a_hook) {
		auto orig = write_call(a_src, a_hook.hook);
		a_hook.orig = unrestricted_cast<F>(orig);
	}
}