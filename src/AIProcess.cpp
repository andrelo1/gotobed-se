#include "AIProcess.h"
#include "Actor.h"
#include "Offsets.h"

namespace Gotobed
{
	std::uintptr_t OnSitSleepStateChange_Orig_Addr{0};

	void AIProcess::OnSitSleepStateChange_Orig(Actor* a_actor, std::uint32_t a_newState, RE::RefHandle* a_refHandle, std::int32_t a_marker) {
		using func_t = decltype(&AIProcess::OnSitSleepStateChange_Orig);
		REL::Relocation<func_t> func(OnSitSleepStateChange_Orig_Addr);
		func(this, a_actor, a_newState, a_refHandle, a_marker);
	}
	
	void AIProcess::OnSitSleepStateChange_Hook(Actor* a_actor, std::uint32_t a_newState, RE::RefHandle* a_refHandle, std::int32_t a_marker) {
		OnSitSleepStateChange_Orig(a_actor, a_newState, a_refHandle, a_marker);

		if (a_actor) {
			auto sitSleepState = a_actor->actorState1.sitSleepState;
			if (sitSleepState == RE::SIT_SLEEP_STATE::kNormal || sitSleepState == RE::SIT_SLEEP_STATE::kWantToSleep || sitSleepState == RE::SIT_SLEEP_STATE::kIsSleeping) {
				a_actor->UpdateOutfit();
			}
		}
	}

	void AIProcess::InstallHooks() {
		OnSitSleepStateChange_Orig_Addr = Offsets::AIProcess::OnSitSleepStateChange.address();
		auto OnSitSleepStateChange_Hook_Addr = &AIProcess::OnSitSleepStateChange_Hook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&OnSitSleepStateChange_Orig_Addr), reinterpret_cast<PVOID&>(OnSitSleepStateChange_Hook_Addr));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}
}