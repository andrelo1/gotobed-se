#pragma once

namespace Gotobed::Offsets
{
	namespace
	{
		constexpr REL::ID ShowMessageBox{52269};
		constexpr REL::ID ShowSleepWaitMenu{52490} ;
		constexpr REL::ID unk_2FE95F8{406356};
	}

	namespace TESFurniture
	{
		constexpr REL::ID Activate{17420};
	}

	namespace TESObjectREFR
	{
		constexpr REL::ID GetCurrentLocation{19812};
		constexpr REL::ID GetFreeMarker{20162};
		constexpr REL::ID SetMarkerReserved{20160};
		constexpr REL::ID SetMarkerUsed{20159};
	}

	namespace Actor
	{
		constexpr REL::ID FinishLoadGame{37652};
	}

	namespace PlayerCharacter
	{
		constexpr REL::ID Update{40447};
		constexpr REL::ID CanSleepWait{40443};
	}

	namespace ExtraReservedMarkers
	{
		constexpr REL::ID vtbl{190349};
	}

	namespace ExtraUsedMarkers
	{
		constexpr REL::ID vtbl{190347};
	}

	namespace AIProcess
	{
		constexpr REL::ID OnSitSleepStateChange{39912};
		constexpr REL::ID sub_674B60{39292};
		constexpr REL::ID SetTarget{39139};
	}

	namespace BGSProcedureSitSleepExecState
	{
		constexpr REL::ID Process{29144};
		constexpr REL::ID ActivateTarget{29150};
	}

	namespace MenuOpenHandler
	{
		constexpr REL::ID CanProcess{52259};
		constexpr REL::ID ProcessButton{52249};
	}
}