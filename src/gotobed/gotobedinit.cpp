#include "gotobedinit.h"
#include "Offsets.h"
#include "MenuOpenHandler.h"
#include "AIProcess.h"
#include "UIUtil.h"
#include "Fixes.h"

namespace Gotobed
{
	void Init()
	{
		// don't show sleep menu on bed activation
		REL::safe_write(Offsets::TESFurniture::Activate.address() + 0x0177, static_cast<std::uint16_t>(0x0CEB));
		// don't show serve time message on bed activation
		REL::safe_write(Offsets::TESFurniture::Activate.address() + 0x0113, static_cast<std::uint8_t>(0xEB));
		// get up from bed using movement keys
		REL::safe_write(Offsets::PlayerCharacter::Update.address() + 0x063E, static_cast<std::uint8_t>(0x02));
		// don't allow sleeping if bed is reserved
		REL::safe_write(Offsets::PlayerCharacter::CanSleepWait.address() + 0x01B0, static_cast<std::uint8_t>(0x00));
		// don't pause character animations while sleeping
		REL::safe_write(Offsets::AIProcess::OnSitSleepStateChange.address() + 0x033F, static_cast<std::uint8_t>(0xEB));
		REL::safe_write(Offsets::AIProcess::sub_674B60.address() + 0x013C, static_cast<std::uint8_t>(0xEB));
		REL::safe_write(Offsets::Actor::FinishLoadGame.address() + 0x01B3, static_cast<std::uint8_t>(0xEB));

		// override Wait button
		MenuOpenHandler::Init();

#ifndef NOJC
		AIProcessNS::Init();
#endif
		UIUtil::Register();

		Fixes::MultipleMarkersReservation::Install();
	}
}