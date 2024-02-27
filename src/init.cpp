#include "init.h"
#include "Settings.h"
#include "Offsets.h"
#include "MenuOpenHandler.h"
#include "AIProcess.h"
#include "UIUtil.h"
#include "SettingsPapyrus.h"
#include "ActorData.h"
#include "TESObjectREFR.h"

namespace Gotobed
{
	void OnSave(SKSE::SerializationInterface* a_intfc) {
		if (!a_intfc) {
			return;
		}

		ActorData::Save(*a_intfc);
	}

	void OnLoad(SKSE::SerializationInterface* a_intfc) {
		if (!a_intfc) {
			return;
		}

		std::uint32_t type, version, length;

		while (a_intfc->GetNextRecordInfo(type, version, length)) {
			ActorData::Load(*a_intfc, type, version, length);
		}
	}

	void OnDataLoaded() {
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

		MenuOpenHandler::InstallHooks();
		AIProcess::InstallHooks();
		TESObjectREFR::InstallHooks();

		// papyrus
		UIUtil::Register();
		SettingsPapyrus::Register();

		auto serialization = SKSE::GetSerializationInterface();
		serialization->SetUniqueID(1);
		serialization->SetSaveCallback(OnSave);
		serialization->SetLoadCallback(OnLoad);
	}

	void Init() {
		SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message* a_msg) {
			if (a_msg->type == SKSE::MessagingInterface::kDataLoaded) {
				OnDataLoaded();
			}
		});
	}
}