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
			REL::Relocation<func_t> func{ Offsets::ShowMessageBox.address() };
			return func(a_msg, a_callback, a_unk3, a_unk4, a_unk5, a_args...);
		}

		void ShowSleepWaitMenu(bool a_sleep)
		{
			using func_t = decltype(&ShowSleepWaitMenu);
			REL::Relocation<func_t> func{ Offsets::ShowSleepWaitMenu.address() };
			func(a_sleep);
		}
	}

	bool MenuOpenHandler::ProcessButton_Original(RE::ButtonEvent* a_event)
	{
		using func_t = decltype(&MenuOpenHandler::ProcessButton_Original);
		REL::Relocation<func_t> func{ ProcessButtonAddr };
		return func(this, a_event);
	}

	bool MenuOpenHandler::ProcessButton_Hook(RE::ButtonEvent* a_event)
	{
		if (!a_event || a_event->userEvent != "Wait") {
			return ProcessButton_Original(a_event);
		}

		auto result = false;

		if (a_event->IsDown()) {
			auto ui = RE::UI::GetSingleton();
			if (ui->numPausesGame == 0 && !ui->IsMenuOpen("Fader Menu")) {
				auto player = RE::PlayerCharacter::GetSingleton();
				if (player->actorState1.lifeState != RE::ACTOR_LIFE_STATE::kDying && player->actorState1.lifeState != RE::ACTOR_LIFE_STATE::kDead) {
					if (player->jailSentence > 0 && (player->unkBD8 & 0x40) == 0) {
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
					} else {
						ShowSleepWaitMenu(player->actorState1.sitSleepState == RE::SIT_SLEEP_STATE::kIsSleeping);
					}

					result = true;
				}
			}
		}

		REL::Relocation<std::uint8_t*> unk_2FEA508{ Offsets::unk_2FEA508.address() };
		*unk_2FEA508 = result;

		return result;
	}

	void MenuOpenHandlerNS::Init()
	{
		ProcessButtonAddr = Offsets::MenuOpenHandler::ProcessButton.address();
		auto ProcessButtonHook = &MenuOpenHandler::ProcessButton_Hook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&ProcessButtonAddr), reinterpret_cast<PVOID&>(ProcessButtonHook));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}
}