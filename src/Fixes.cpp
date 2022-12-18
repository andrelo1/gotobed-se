#include "Fixes.h"
#include "Offsets.h"

namespace Gotobed::Fixes
{
	namespace MultipleMarkersReservation
	{
		class TESObjectREFR: public RE::TESObjectREFR
		{
		public:
			bool SetMarkerReserved(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed) {
				auto middleHigh = a_actor->currentProcess->middleHigh;

				if (middleHigh && middleHigh->unk2E4 != a_marker) {					
					if (middleHigh->unk2E4 != -1) {
						hook.call_orig(this, middleHigh->unk2E4, nullptr, false, false);
					}
					middleHigh->unk2E4 = a_marker;
				}
				
				return hook.call_orig(this, a_marker, a_actor, a_reserved, a_ignoreUsed);
			}

			static inline stl::HookData hook{&TESObjectREFR::SetMarkerReserved};
		};

		void Install() {
			stl::write_thunk(Offsets::BGSProcedureSitSleepExecState::ProcessActivate.address() + 0x02B4, TESObjectREFR::hook);
			spdlog::info("Fixes: MultipleMarkersReservation installed");
		}
	}
}