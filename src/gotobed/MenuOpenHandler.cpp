#include "MenuOpenHandler.h"
#include "Offsets.h"

namespace Gotobed
{
	namespace
	{
		std::uintptr_t	ProcessButtonAddr{ 0 };

		template<class... Args>
		bool ShowMessageBox(const char* a_msg, void (*a_callback)(std::uint8_t), std::uint8_t a_unk3, std::uint32_t a_unk4, std::uint32_t a_unk5, Args... a_args)
		{
			using func_t = decltype(&ShowMessageBox<Args...>);
			REL::Relocation<func_t> func{ Offsets::ShowMessageBox };
			return func(a_msg, a_callback, a_unk3, a_unk4, a_unk5, a_args...);
		}

		void ShowSleepWaitMenu(bool a_sleep)
		{
			using func_t = decltype(&ShowSleepWaitMenu);
			REL::Relocation<func_t> func{ Offsets::ShowSleepWaitMenu };
			func(a_sleep);
		}

		void ShowServeSentenceQuestion()
		{
			auto settings = RE::GameSettingCollection::GetSingleton();
			auto sServeSentenceQuestion = settings->GetSetting("sServeSentenceQuestion")->GetString();
			auto sYes = settings->GetSetting("sYes")->GetString();
			auto sNo = settings->GetSetting("sNo")->GetString();
			auto callback = [](std::uint8_t a_idx) {
				if (a_idx == 1) {
					RE::PlayerCharacter::GetSingleton()->ServePrisonTime();
				}
			};

			ShowMessageBox(sServeSentenceQuestion, callback, 1, 0x19, 4, sYes, sNo, nullptr);
		}
	}

	bool MenuOpenHandler::ProcessButtonOrig(RE::ButtonEvent* a_event)
	{
		using func_t = decltype(&MenuOpenHandler::ProcessButtonOrig);
		REL::Relocation<func_t> func{ ProcessButtonAddr };
		return func(this, a_event);
	}

	bool MenuOpenHandler::ProcessButtonHook(RE::ButtonEvent* a_event)
	{
		REL::Relocation<std::uint8_t*> unk_2FE95F8{ Offsets::unk_2FE95F8 };

		if (a_event && a_event->userEvent == "Wait" && a_event->IsDown()) {
			if (OnWaitButtonDown()) {
				unk_2FE95F8 = true;
				return true;
			}
		}

		return ProcessButtonOrig(a_event);
	}

	bool MenuOpenHandler::OnWaitButtonDown()
	{
		auto ui = RE::UI::GetSingleton();

		if (ui->numPausesGame || ui->IsMenuOpen("Fader Menu")) {
			return false;
		}

		auto player = RE::PlayerCharacter::GetSingleton();

		if (player->actorState1.lifeState == RE::ACTOR_LIFE_STATE::kDying || player->actorState1.lifeState == RE::ACTOR_LIFE_STATE::kDead) {
			return false;
		}

		if (player->jailSentence > 0 && (player->unkBD8 & 0x40) == 0) {
			ShowServeSentenceQuestion();
			return true;
		}

		if (player->actorState1.sitSleepState == RE::SIT_SLEEP_STATE::kIsSleeping) {
			ShowSleepWaitMenu(true);
			return true;
		}

		return false;
	}

	void MenuOpenHandler::Init()
	{
		ProcessButtonAddr = Offsets::MenuOpenHandler::ProcessButton.address();
		auto ProcessButtonHookAddr = &ProcessButtonHook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&ProcessButtonAddr), reinterpret_cast<PVOID&>(ProcessButtonHookAddr));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}
}