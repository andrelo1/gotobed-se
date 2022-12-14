#include "UIUtil.h"

namespace Gotobed::UIUtil
{
	void ShowSleepWaitMenu(bool a_sleep) {
		using func_t = decltype(&ShowSleepWaitMenu);
		REL::Relocation<func_t> func{ Offsets::ShowSleepWaitMenu };
		func(a_sleep);
	}

	void ShowServeSentenceQuestion() {
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