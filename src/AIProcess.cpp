#include "AIProcess.h"
#include "Actor.h"
#include "Offsets.h"

namespace Gotobed
{
	namespace Hooks
	{
		stl::HookData OnSitSleepStateChange{&AIProcess::OnSitSleepStateChange};
	}

	void AIProcess::OnSitSleepStateChange(Actor* a_actor, std::uint32_t a_newState, RE::RefHandle& a_refHandle, std::int32_t a_marker) {
		Hooks::OnSitSleepStateChange.call_orig(this, a_actor, a_newState, a_refHandle, a_marker);

		if (a_actor) {
			auto sitSleepState = a_actor->actorState1.sitSleepState;
			if (sitSleepState == RE::SIT_SLEEP_STATE::kNormal || sitSleepState == RE::SIT_SLEEP_STATE::kWantToSleep || sitSleepState == RE::SIT_SLEEP_STATE::kIsSleeping) {
				a_actor->UpdateOutfit();
			}
		}
	}

	void AIProcess::InstallHooks() {
		stl::write_detour(Offsets::AIProcess::OnSitSleepStateChange.address(), Hooks::OnSitSleepStateChange);
	}
}