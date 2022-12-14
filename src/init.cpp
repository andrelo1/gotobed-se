#include "init.h"
#include "Settings.h"
#include "Offsets.h"
#include "MenuOpenHandler.h"
#include "AIProcess.h"
#include "UIUtilPapyrus.h"
#include "Fixes.h"
#include "JCApi.h"
#include "SKSEMessaging.h"
#include "UIUtil.h"

namespace Gotobed
{
	void Init() {
		auto& settings = Settings::Get();
		settings.Read();

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

		// hook Wait button
		MenuOpenHandler::Init();

		// install fixes
		if (settings.fixes.multipleMarkersReservation) {
			Fixes::MultipleMarkersReservation::Install();
		}

		jc::api::init([]() {
			if (!jc::api::ready() || !jc::api::setDefaultDomain("GTB_JCDomain")) {
				return;
			}

			// hook actor sleep state
			AIProcess::Init();
		});

		SKSE::Messaging::RegisterForSKSE([](SKSE::MessagingInterface::Message* a_msg) {
			if (a_msg && a_msg->type == SKSE::MessagingInterface::kPostLoadGame) {
				if (!jc::api::ready()) {
					std::thread([]() {
						std::this_thread::sleep_for(std::chrono::seconds(5));
						UIUtil::ShowMessageBox("GOTOBED\n\nError: JContainers api was not initialized.\nSome features won't be available.", nullptr, 0, 4, 10, "OK", nullptr);
					}).detach();
				}
			}
		});

		// register papyrus
		UIUtilPapyrus::Register();
	}
}