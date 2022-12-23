#include "MenuOpenHandler.h"
#include "Offsets.h"
#include "UIUtil.h"

namespace Gotobed
{
	namespace Hooks
	{
		stl::HookData ProcessButton{&MenuOpenHandler::ProcessButtonHook};
	}

	bool MenuOpenHandler::ProcessButtonHook(RE::ButtonEvent* a_event) {
		REL::Relocation<std::uint8_t*> unk_2FE95F8{Offsets::unk_2FE95F8};

		if (a_event && a_event->userEvent == "Wait" && a_event->IsDown()) {
			if (OnWaitButtonDown()) {
				unk_2FE95F8 = true;
				return true;
			}
		}

		return Hooks::ProcessButton.call_orig(this, a_event);
	}

	bool MenuOpenHandler::OnWaitButtonDown() {
		auto ui = RE::UI::GetSingleton();

		if (ui->numPausesGame || ui->IsMenuOpen("Fader Menu")) {
			return false;
		}

		auto player = RE::PlayerCharacter::GetSingleton();

		if (player->actorState1.lifeState == RE::ACTOR_LIFE_STATE::kDying || player->actorState1.lifeState == RE::ACTOR_LIFE_STATE::kDead) {
			return false;
		}

		if (player->jailSentence > 0 && (player->unkBD8 & 0x40) == 0) {
			UIUtil::ShowServeSentenceQuestion();
			return true;
		}

		if (player->actorState1.sitSleepState == RE::SIT_SLEEP_STATE::kIsSleeping) {
			UIUtil::ShowSleepWaitMenu(true);
			return true;
		}

		return false;
	}

	void MenuOpenHandler::InstallHooks() {
		Hooks::ProcessButton.write_detour(Offsets::MenuOpenHandler::ProcessButton.address());
	}
}