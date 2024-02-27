#include "TESObjectREFR.h"
#include "Settings.h"
#include "Offsets.h"

namespace Gotobed {
	bool TESObjectREFR::SetMarkerReserved_Orig(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed) {
		using func_t = decltype(&TESObjectREFR::SetMarkerReserved_Orig);
		REL::Relocation<func_t> func{Offsets::TESObjectREFR::SetMarkerReserved};
		return func(this, a_marker, a_actor, a_reserved, a_ignoreUsed);
	}

	bool TESObjectREFR::SetMarkerReserved_Hook(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed) {
		auto middleHigh = a_actor->currentProcess->middleHigh;

		if (middleHigh && middleHigh->unk2E4 != a_marker) {					
			if (middleHigh->unk2E4 != -1) {
				SetMarkerReserved_Orig(middleHigh->unk2E4, nullptr, false, false);
			}
			middleHigh->unk2E4 = a_marker;
		}

		return SetMarkerReserved_Orig(a_marker, a_actor, a_reserved, a_ignoreUsed);
	}

	void TESObjectREFR::InstallHooks() {
		auto& settings = Settings::Get();

		if (settings.fixes.multipleMarkersReservation) {
			auto SetMarkerReserved_Hook_Addr = &TESObjectREFR::SetMarkerReserved_Hook;
			auto& trampoline = SKSE::GetTrampoline();
			SKSE::AllocTrampoline(14);
			trampoline.write_call<5>(Offsets::BGSProcedureSitSleepExecState::ActivateTarget.address() + 0x02B4, reinterpret_cast<std::uintptr_t&>(SetMarkerReserved_Hook_Addr));
		}
	}
}