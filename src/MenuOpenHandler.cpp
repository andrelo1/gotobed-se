#include "MenuOpenHandler.h"
#include "Offsets.h"
#include "UIFuncs.h"
#include "Settings.h"

namespace Gotobed
{
	std::uintptr_t CanProcess_Orig_Addr{0};
	std::uintptr_t ProcessButton_Orig_Addr{0};

	namespace detail
	{
		bool IsKeyPressed(std::uint32_t a_key) {
			return RE::BSInputDeviceManager::GetSingleton()->GetKeyboard()->IsPressed(a_key);
		}

		bool IsSleepKey(RE::ButtonEvent* a_event) {
			auto& settings = Settings::Get();
			return a_event && (settings.keys.sleep != -1 ? a_event->idCode == settings.keys.sleep : a_event->userEvent == "Wait");
		}

		bool IsServeTimeKey(RE::ButtonEvent* a_event) {
			auto& settings = Settings::Get();
			return a_event && (settings.keys.serveTime != -1 ? a_event->idCode == settings.keys.serveTime : a_event->userEvent == "Wait");
		}
	}

	bool MenuOpenHandler::CanProcess_Orig(RE::InputEvent* a_event) {
		using func_t = decltype(&MenuOpenHandler::CanProcess_Orig);
		REL::Relocation<func_t> func{CanProcess_Orig_Addr};
		return func(this, a_event);
	}

	bool MenuOpenHandler::CanProcess_Hook(RE::InputEvent* a_event) {
		if (a_event && a_event->eventType == RE::INPUT_EVENT_TYPE::kButton) {
			if (detail::IsSleepKey(a_event->AsButtonEvent()) || detail::IsServeTimeKey(a_event->AsButtonEvent())) {
				return true;
			}
		}

		return CanProcess_Orig(a_event);
	}

	bool MenuOpenHandler::ProcessButton_Orig(RE::ButtonEvent* a_event) {
		using func_t = decltype(&MenuOpenHandler::ProcessButton_Orig);
		REL::Relocation<func_t> func{ProcessButton_Orig_Addr};
		return func(this, a_event);
	}

	bool MenuOpenHandler::ProcessButton_Hook(RE::ButtonEvent* a_event) {
		auto& settings = Settings::Get();

		if (a_event && a_event->IsDown()) {
			if (detail::IsServeTimeKey(a_event) && (settings.keys.serveTimeMod == -1 || detail::IsKeyPressed(settings.keys.serveTimeMod)) && OnServeTimeButtonDown()) {
				return true;
			}

			if (detail::IsSleepKey(a_event) && (settings.keys.sleepMod == -1 || detail::IsKeyPressed(settings.keys.sleepMod)) && OnSleepButtonDown()) {
				return true;
			}
		}

		return ProcessButton_Orig(a_event);
	}

	bool MenuOpenHandler::OnSleepButtonDown() {
		auto ui = RE::UI::GetSingleton();

		if (ui->numPausesGame || ui->IsMenuOpen(RE::FaderMenu::MENU_NAME)) {
			return false;
		}

		auto player = RE::PlayerCharacter::GetSingleton();

		if (player->actorState1.lifeState == RE::ACTOR_LIFE_STATE::kDying || player->actorState1.lifeState == RE::ACTOR_LIFE_STATE::kDead) {
			return false;
		}

		if (player->actorState1.sitSleepState != RE::SIT_SLEEP_STATE::kIsSleeping) {
			return false;
		}

		UIFuncs::ShowSleepWaitMenu(true);

		return true;
	}

	bool MenuOpenHandler::OnServeTimeButtonDown() {
		auto ui = RE::UI::GetSingleton();

		if (ui->numPausesGame || ui->IsMenuOpen(RE::FaderMenu::MENU_NAME)) {
			return false;
		}

		auto player = RE::PlayerCharacter::GetSingleton();

		if (player->actorState1.lifeState == RE::ACTOR_LIFE_STATE::kDying || player->actorState1.lifeState == RE::ACTOR_LIFE_STATE::kDead) {
			return false;
		}

		if (player->jailSentence <= 0 || (player->unkBD8 & 0x40) != 0) {
			return false;
		}

		UIFuncs::ShowServeSentenceQuestion();

		return true;
	}

	void MenuOpenHandler::InstallHooks() {
		CanProcess_Orig_Addr = Offsets::MenuOpenHandler::CanProcess.address();
		auto CanProcess_Hook_Addr = &MenuOpenHandler::CanProcess_Hook;
		ProcessButton_Orig_Addr = Offsets::MenuOpenHandler::ProcessButton.address();
		auto ProcessButton_Hook_Addr = &MenuOpenHandler::ProcessButton_Hook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&CanProcess_Orig_Addr), reinterpret_cast<PVOID&>(CanProcess_Hook_Addr));
		DetourAttach(reinterpret_cast<PVOID*>(&ProcessButton_Orig_Addr), reinterpret_cast<PVOID&>(ProcessButton_Hook_Addr));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}
} 