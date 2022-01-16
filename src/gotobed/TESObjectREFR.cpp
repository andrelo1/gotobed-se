#include "TESObjectREFR.h"
#include "Offsets.h"
#include "ExtraReservedMarkers.h"
#include "ExtraUsedMarkers.h"

namespace Gotobed
{
	namespace
	{
		//std::uintptr_t SetMarkerReservedAddr{ 0 };
		//std::uintptr_t SetMarkerUsedAddr{ 0 };
		//std::uintptr_t GetFreeMarkerAddr{ 0 };
	}

	bool TESObjectREFR::SetMarkerReserved_Hook(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed)
	{
		RE::BSWriteLockGuard lock(*reinterpret_cast<RE::BSReadWriteLock*>(reinterpret_cast<std::uint8_t*>(this) + offsetof(RE::TESObjectREFR, extraList) + 0x10));
		
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

	/*
	bool TESObjectREFR::SetMarkerReserved(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed)
	{
		spdlog::info(FMT_STRING("{:<20} ref={:08x} a_marker={} a_actor={:08x} {:<5} {:<5}"), "SetMarkerReserved", formID, a_marker, a_actor ? a_actor->formID : 0, a_reserved, a_ignoreUsed);

		using func_t = decltype(&TESObjectREFR::SetMarkerReserved);
		REL::Relocation<func_t> func{ SetMarkerReservedAddr };
		return func(this, a_marker, a_actor, a_reserved, a_ignoreUsed);
	}
	*/

	/*
	bool TESObjectREFR::SetMarkerReserved(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed)
	{
		AddChange(0x80000000);

		if (!a_ignoreUsed) {
			auto usedMarkers = extraList.GetByType<ExtraUsedMarkers>();

			if (usedMarkers) {
				// using extraList's lock because used markers have no lock
				RE::BSReadLockGuard lock(*(RE::BSReadWriteLock*)(this + offsetof(RE::TESObjectREFR, extraList) + 0x10));

				if (usedMarkers->IsUsed(a_marker) && (!a_actor || a_actor != usedMarkers->GetActor(a_marker))) {
					return false;
				}
			}
		}

		auto reservedMarkers = extraList.GetByType<ExtraReservedMarkers>();

		if (!reservedMarkers) {
			reservedMarkers = RE::BSExtraData::Create<ExtraReservedMarkers>(REL::ID(235661).address());
			extraList.Add(reservedMarkers);
		}

		reservedMarkers->SetReserved(a_marker, a_actor, a_reserved);

		return true;
	}
	*/

	/*
	bool TESObjectREFR::SetMarkerReserved(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed)
	{
		bool flag1 = true;

		extraList._lock.LockForWrite();

		AddChange(0x80000000);

		if (a_actor && a_reserved) {
			auto usedMarkers = extraList.GetByType<RE::ExtraUsedMarkers>();
			
			if (usedMarkers) {
				RE::Actor* actor = usedMarkers->GetActor(marker);
				flag1 = !(actor && actor != a_actor && !a_ignoreUsed);
			}
		}

		if (flag1) {
			extraList._lock.LockForRead();
			auto reservedMarkers = extraList.GetByType<RE::ExtraReservedMarkers>();
			extraList._lock.UnlockForRead();

			if (a_reserved && !reservedMarkers) {
				// add reserved markers
			}

			if (reservedMarkers) {
				reservedMarkers->SetReserved(a_marker, a_actor, a_reserved);
			}
		}

		extraList._lock.UnlockForWrite();

		return flag1;
	}
	*/

	bool TESObjectREFR::SetMarkerUsed_Hook(std::uint32_t a_marker, RE::Actor* a_actor, bool a_used, bool a_ignoreReserved)
	{
		RE::BSWriteLockGuard lock(*reinterpret_cast<RE::BSReadWriteLock*>(reinterpret_cast<std::uint8_t*>(this) + offsetof(RE::TESObjectREFR, extraList) + 0x10));

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

	/*
	bool TESObjectREFR::SetMarkerUsed(std::uint32_t a_marker, RE::Actor* a_actor, bool a_used, bool a_ignoreReserved)
	{
		spdlog::info(FMT_STRING("{:<20} ref={:08x} a_marker={} a_actor={:08x} {:<5} {:<5}"), "SetMarkerUsed", formID, a_marker, a_actor ? a_actor->formID : 0, a_used, a_ignoreReserved);

		using func_t = decltype(&TESObjectREFR::SetMarkerUsed);
		REL::Relocation<func_t> func{ SetMarkerUsedAddr };
		return func(this, a_marker, a_actor, a_used, a_ignoreReserved);
	}
	*/

	/*bool TESObjectREFR::SetMarkerUsed(std::uint32_t a_marker, RE::Actor* a_actor, bool a_used, bool a_ignoreReserved)
	{
		AddChange(0x80000000);

		if (!a_ignoreReserved) {
			auto reservedMarkers = extraList.GetByType<ExtraReservedMarkers>();

			if (reservedMarkers) {
				if (reservedMarkers->IsReserved(a_marker) && (!a_actor || a_actor != reservedMarkers->GetActor(a_marker))) {
					return false;
				}
			}
		}

		auto usedMarkers = extraList.GetByType<ExtraUsedMarkers>();

		if (!usedMarkers) {
			usedMarkers = RE::BSExtraData::Create<ExtraUsedMarkers>(REL::ID(235660).address());
			extraList.Add(usedMarkers);
		}

		usedMarkers->SetUsed(a_marker, a_actor, a_used);

		return true;
	}*/

	/*bool TESObjectREFR::SetMarkerUsed(std::uint32_t a_marker, RE::Actor* a_actor, bool a_used, bool a_ignoreReserved)
	{
		extraList._lock.LockForWrite();

		bool flag1 = true;

		AddChange(0x80000000);

		extraList._lock.LockForRead();
		auto usedMarkers = extraList.GetByType<RE::ExtraUsedMarkers>();
		extraList._lock.UnlockForRead();

		bool flag2 = usedMarkers && usedMarkers->HasMarker(a_marker);

		if (a_used && !usedMarkers) {
			// add used markers
		}

		if (usedMarkers) {
			if (!a_ignoreReserved) {
				auto reservedMarkers = extraList.GetByType<RE::ExtraReservedMarkers>();
				RE::Actor* actor = reservedMarkers->GetActor(marker);
				flag1 = !actor || actor == a_actor;
			}

			if (flag1) {
				RE::Actor* actor = usedMarkers.GetActor(marker);
				flag1 = !actor || actor == a_actor;

				usedMarkers.SetUsed(a_marker, a_actor, a_used);
			}
		}

		if (flag1) {
			if (a_actor != RE::PlayerCharacter::GetSingleton() && !a_used && flag2) {
				auto reservedMarkers = extraList.GetByType<RE::ExtraReservedMarkers>();
				if (reservedMarkers) {
					reservedMarkers.SetReserved(a_marker, a_actor, false);
				}
			}
		}

		extraList._lock.UnlockForWrite();

		return flag1;
	}*/

	/*
	std::int32_t TESObjectREFR::GetFreeMarker(RE::Actor* a_actor, bool a_ignoreReserved)
	{
		using func_t = decltype(&TESObjectREFR::GetFreeMarker);
		REL::Relocation<func_t> func{ GetFreeMarkerAddr };
		return func(this, a_actor, a_ignoreReserved);
	}
	*/

	/*std::int32_t TESObjectREFR::GetFreeMarker(RE::Actor* a_actor, bool a_ignoreReserved)
	{
		extraList._lock.LockForRead();

		std::int32_t marker = -1;

		extraList._lock.LockForRead();
		auto reservedMarkers = extraList.GetByType<RE::ExtraReservedMarkers>();
		extraList._lock.UnlockRead();

		RE::Actor* actor = nullptr;

		if (GetBaseObject()->GetFormType() == RE::FormType::Furniture) {
			bool continue_ = true;

			for (std::uint32_t i = 0; i < 0x19 && continue_; i++) {
				if (GetBaseObject()->furnFlags.underlying() & 1 << i) {
					extraList._lock.LockForRead();
					auto usedMarkers = extraList.GetByType<RE::ExtraUsedMarkers>();
					extraList._lock.UnlockRead();

					if (usedMarkers) {
						actor = usedMarkers->GetActor(i);
					}

					if (!actor && !a_ignoreReserved && reservedMarkers) {
						actor = reservedMarkers->GetActor(i);
					}

					RE::BGSKeyword* keyword = GetBaseObject()->GetMarkerKeyword(i);

					if (!actor && (!a_actor || !keyword || a_actor->HasKeywordHelper(keyword)) || actor == a_actor) {
						marker = i;
						continue_ = false;
					}
				}
			};
		} else {
			extraList._lock.LockForRead();
			auto usedMarkers = extraList.GetByType<RE::ExtraUsedMarkers>();
			extraList._lock.UnlockRead();

			if (usedMarkers) {
				actor = usedMarkers->GetActor(0);
			}

			if (!actor && !a_ignoreReserved && reservedMarkers) {
				actor = reservedMarkers->GetActor(0);
			}

			if (!actor || actor == a_actor) {
				marker = 0;
			}
		}

		extraList._lock.UnlockRead();

		return marker;
	}*/

	void TESObjectREFRNS::Init()
	{
		auto SetMarkerReservedAddr = Offsets::TESObjectREFR::SetMarkerReserved.address();
		auto SetMarkerReservedHook = &TESObjectREFR::SetMarkerReserved_Hook;
		auto SetMarkerUsedAddr = Offsets::TESObjectREFR::SetMarkerUsed.address();
		auto SetMarkerUsedHook = &TESObjectREFR::SetMarkerUsed_Hook;
		//GetFreeMarkerAddr = REL::ID(19767).address();

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&SetMarkerReservedAddr), reinterpret_cast<PVOID&>(SetMarkerReservedHook));
		DetourAttach(reinterpret_cast<PVOID*>(&SetMarkerUsedAddr), reinterpret_cast<PVOID&>(SetMarkerUsedHook));
		//DetourAttach(&(PVOID&)GetFreeMarkerAddr, SKSE::stl::unrestricted_cast<PVOID>(&TESObjectREFR::GetFreeMarker));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}
}