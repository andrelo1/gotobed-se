#include "AIProcess.h"
#include "Actor.h"
#include "Offsets.h"

namespace Gotobed
{
	namespace
	{
		std::uintptr_t OnSitSleepStateChangeAddr{ 0 };
	}

	void AIProcess::OnSitSleepStateChange(Actor* a_actor, std::uint32_t a_newState, RE::RefHandle& a_refHandle, std::int32_t a_marker)
	{
		using func_t = decltype(&AIProcess::OnSitSleepStateChange);
		REL::Relocation<func_t> func{ OnSitSleepStateChangeAddr };
		func(this, a_actor, a_newState, a_refHandle, a_marker);
	}

	void AIProcess::OnSitSleepStateChangeHook(Actor* a_actor, std::uint32_t a_newState, RE::RefHandle& a_refHandle, std::int32_t a_marker)
	{
		OnSitSleepStateChange(a_actor, a_newState, a_refHandle, a_marker);

		if (a_actor) {
			auto sitSleepState = a_actor->actorState1.sitSleepState;
			if (sitSleepState == RE::SIT_SLEEP_STATE::kNormal || sitSleepState == RE::SIT_SLEEP_STATE::kWantToSleep || sitSleepState == RE::SIT_SLEEP_STATE::kIsSleeping) {
				a_actor->UpdateOutfit();
			}
		}
	}

	void AIProcess::Init()
	{
		OnSitSleepStateChangeAddr = Offsets::AIProcess::OnSitSleepStateChange.address();
		auto OnSitSleepStateChangeHookAddr = &AIProcess::OnSitSleepStateChangeHook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&OnSitSleepStateChangeAddr), reinterpret_cast<PVOID&>(OnSitSleepStateChangeHookAddr));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}
}