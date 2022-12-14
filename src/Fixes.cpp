#include "Fixes.h"
#include "Offsets.h"

namespace Gotobed::Fixes
{
	namespace MultipleMarkersReservation
	{
		struct SetMarkerReserved
		{
			static bool thunk(RE::TESObjectREFR* a_this, std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed) {
				auto middleHigh = a_actor->currentProcess->middleHigh;

				if (middleHigh && middleHigh->unk2E4 != a_marker) {					
					if (middleHigh->unk2E4 != -1) {
						func(a_this, middleHigh->unk2E4, nullptr, false, false);
					}
					middleHigh->unk2E4 = a_marker;
				}

				return func(a_this, a_marker, a_actor, a_reserved, a_ignoreUsed);
			}

			static inline REL::Relocation<decltype(&thunk)> func;
		};

		void Install() {
			stl::write_thunk_call<SetMarkerReserved>(Offsets::BGSProcedureSitSleepExecState::ProcessActivate.address() + 0x02B4);
			spdlog::info("Fixes: MultipleMarkersReservation installed");
		}
	}
}