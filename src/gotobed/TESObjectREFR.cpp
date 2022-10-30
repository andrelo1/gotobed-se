#include "TESObjectREFR.h"
#include "Offsets.h"
#include "ExtraReservedMarkers.h"
#include "ExtraUsedMarkers.h"

namespace Gotobed
{
	bool TESObjectREFR::SetMarkerReserved_Hook(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed)
	{
#ifdef VERSION_AE_1_6_640
		RE::BSWriteLockGuard lock(*reinterpret_cast<RE::BSReadWriteLock*>(reinterpret_cast<std::uint8_t*>(this) + offsetof(RE::TESObjectREFR, extraList) + 0x18));
#else
		RE::BSWriteLockGuard lock(*reinterpret_cast<RE::BSReadWriteLock*>(reinterpret_cast<std::uint8_t*>(this) + offsetof(RE::TESObjectREFR, extraList) + 0x10));
#endif
		
		AddChange(0x80000000);

		RE::ActorHandle actor{ a_actor };

		auto usedMarkers = extraList.GetByType<ExtraUsedMarkers>();

		if (!usedMarkers) {
			usedMarkers = RE::BSExtraData::Create<ExtraUsedMarkers>(Offsets::ExtraUsedMarkers::vtbl.address());
			extraList.Add(usedMarkers);
		}

		auto reservedMarkers = extraList.GetByType<ExtraReservedMarkers>();
		
		if (!reservedMarkers) {
			reservedMarkers = RE::BSExtraData::Create<ExtraReservedMarkers>(Offsets::ExtraReservedMarkers::vtbl.address());
			extraList.Add(reservedMarkers);
		}

		if (a_reserved && !a_ignoreUsed) {
			auto marker = usedMarkers->GetMarker(a_marker);
			if (marker && (!marker->actor || marker->actor != actor)) {
				return false;
			}
		}

		if (a_reserved && actor) {
			auto end = std::remove_if(reservedMarkers->entries.begin(), reservedMarkers->entries.end(), [&](auto& a_entry) { return a_entry.actor == actor && a_entry.marker != a_marker; });
			reservedMarkers->entries.resize(static_cast<decltype(reservedMarkers->entries)::size_type>(std::distance(reservedMarkers->entries.begin(), end)));
		}

		auto marker = reservedMarkers->GetMarker(a_marker);

		if (a_reserved) {
			if (!marker) {
				marker = &reservedMarkers->entries.emplace_back();
			}

			*marker = { actor, a_marker, 5.0e+9f };
		} else {
			if (marker) {
				reservedMarkers->entries.erase(marker);
			}
		}
	
		return true;
	}

	bool TESObjectREFR::SetMarkerUsed_Hook(std::uint32_t a_marker, RE::Actor* a_actor, bool a_used, bool a_ignoreReserved)
	{
#ifdef VERSION_AE_1_6_640
		RE::BSWriteLockGuard lock(*reinterpret_cast<RE::BSReadWriteLock*>(reinterpret_cast<std::uint8_t*>(this) + offsetof(RE::TESObjectREFR, extraList) + 0x18));
#else
		RE::BSWriteLockGuard lock(*reinterpret_cast<RE::BSReadWriteLock*>(reinterpret_cast<std::uint8_t*>(this) + offsetof(RE::TESObjectREFR, extraList) + 0x10));
#endif

		AddChange(0x80000000);

		RE::ActorHandle actor{ a_actor };

		auto usedMarkers = extraList.GetByType<ExtraUsedMarkers>();

		if (!usedMarkers) {
			usedMarkers = RE::BSExtraData::Create<ExtraUsedMarkers>(Offsets::ExtraUsedMarkers::vtbl.address());
			extraList.Add(usedMarkers);
		}

		auto reservedMarkers = extraList.GetByType<ExtraReservedMarkers>();

		if (!reservedMarkers) {
			reservedMarkers = RE::BSExtraData::Create<ExtraReservedMarkers>(Offsets::ExtraReservedMarkers::vtbl.address());
			extraList.Add(reservedMarkers);
		}

		if (a_used && !a_ignoreReserved) {
			auto marker = reservedMarkers->GetMarker(a_marker);
			if (marker && (!marker->actor || marker->actor != actor)) {
				return false;
			}
		}

		if (a_used && actor) {
			auto end = std::remove_if(usedMarkers->entries.begin(), usedMarkers->entries.end(), [&](auto& a_entry) { return a_entry.actor == actor && a_entry.marker != a_marker; });
			usedMarkers->entries.resize(static_cast<decltype(usedMarkers->entries)::size_type>(std::distance(usedMarkers->entries.begin(), end)));
		}

		if (!a_used) {
			auto marker = reservedMarkers->GetMarker(a_marker);
			if (marker) {
				reservedMarkers->entries.erase(marker);
			}
		}

		auto marker = usedMarkers->GetMarker(a_marker);

		if (a_used) {
			if (!marker) {
				marker = &usedMarkers->entries.emplace_back();
			}

			*marker = { actor, a_marker, 0.0f };
		} else {
			if (marker) {
				usedMarkers->entries.erase(marker);
			}
		}

		return true;
	}

	void TESObjectREFRNS::Init()
	{
		auto SetMarkerReservedAddr = Offsets::TESObjectREFR::SetMarkerReserved.address();
		auto SetMarkerReservedHook = &TESObjectREFR::SetMarkerReserved_Hook;
		auto SetMarkerUsedAddr = Offsets::TESObjectREFR::SetMarkerUsed.address();
		auto SetMarkerUsedHook = &TESObjectREFR::SetMarkerUsed_Hook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&SetMarkerReservedAddr), reinterpret_cast<PVOID&>(SetMarkerReservedHook));
		DetourAttach(reinterpret_cast<PVOID*>(&SetMarkerUsedAddr), reinterpret_cast<PVOID&>(SetMarkerUsedHook));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}
}