#pragma once

namespace Gotobed::Offsets
{
	namespace
	{
		constexpr REL::ID ShowMessageBox{51420};
		constexpr REL::ID ShowSleepWaitMenu{51618};
		constexpr REL::ID unk_2FE95F8{519814};
	}

	namespace TESFurniture
	{
		constexpr REL::ID Activate{17034};
	}

	namespace TESObjectREFR
	{
		constexpr REL::ID GetCurrentLocation{19385};
		constexpr REL::ID GetFreeMarker{19767};
		constexpr REL::ID SetMarkerReserved{19765};
		constexpr REL::ID SetMarkerUsed{19764};
	}

	namespace Actor
	{
		constexpr REL::ID FinishLoadGame{36644};
	}

	namespace PlayerCharacter
	{
		constexpr REL::ID Update{39375};
		constexpr REL::ID CanSleepWait{39371};
	}

	namespace ExtraReservedMarkers
	{
		constexpr REL::ID vtbl{235661};
	}

	namespace ExtraUsedMarkers
	{
		constexpr REL::ID vtbl{235660};
	}

	namespace AIProcess
	{
		constexpr REL::ID OnSitSleepStateChange{38871};
		constexpr REL::ID sub_674B60{38317};
		constexpr REL::ID SetTarget{38778};
	}

	namespace BGSProcedureSitSleepExecState
	{
		constexpr REL::ID Process{28394};
		constexpr REL::ID ActivateTarget{28400};
	}

	namespace MenuOpenHandler
	{
		constexpr REL::ID CanProcess{51410};
		constexpr REL::ID ProcessButton{51400};
	}
}