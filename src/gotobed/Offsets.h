#pragma once

namespace Gotobed::Offsets
{
	namespace
	{
		constexpr REL::ID ShowMessageBox{ static_cast<std::uint64_t>(52269) };
		constexpr REL::ID ShowSleepWaitMenu{ static_cast<std::uint64_t>(52490)} ;
		constexpr REL::ID unk_2FE95F8{ static_cast<std::uint64_t>(406356) };
	}

	namespace TESFurniture
	{
		constexpr REL::ID Activate{ static_cast<std::uint64_t>(17420) };
	}

	namespace TESObjectREFR
	{
		constexpr REL::ID GetCurrentLocation{ static_cast<std::uint64_t>(19812) };
		constexpr REL::ID SetMarkerReserved{ static_cast<std::uint64_t>(20160) };
		constexpr REL::ID SetMarkerUsed{ static_cast<std::uint64_t>(20159) };
	}

	namespace Actor
	{
		constexpr REL::ID FinishLoadGame{ static_cast<std::uint64_t>(37652) };
	}

	namespace PlayerCharacter
	{
		constexpr REL::ID Update{ static_cast<std::uint64_t>(40447) };
		constexpr REL::ID CanSleepWait{ static_cast<std::uint64_t>(40443) };
	}

	namespace ExtraReservedMarkers
	{
		constexpr REL::ID vtbl{ static_cast<std::uint64_t>(190349) };
	}

	namespace ExtraUsedMarkers
	{
		constexpr REL::ID vtbl{ static_cast<std::uint64_t>(190347) };
	}

	namespace AIProcess
	{
		constexpr REL::ID OnSitSleepStateChange{ static_cast<std::uint64_t>(39912) };
		constexpr REL::ID sub_674B60{ static_cast<std::uint64_t>(39292) };
	}

	namespace BGSProcedureSitSleepExecState
	{
		constexpr REL::ID ProcessActivate{ static_cast<std::uint64_t>(29150) };
	}

	namespace MenuOpenHandler
	{
		constexpr REL::ID ProcessButton{ static_cast<std::uint64_t>(52249) };
	}
}