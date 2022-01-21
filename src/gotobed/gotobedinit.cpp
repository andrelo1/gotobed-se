#include "gotobedinit.h"
#include "TESObjectREFR.h"
#include "Misc.h"
#include "MenuOpenHandler.h"
#include "AIProcess.h"
#include "UIUtil.h"

namespace Gotobed
{
	void Init()
	{
		MenuOpenHandlerNS::Init();
		AIProcessNS::Init();
		TESObjectREFRNS::Init();
		UIUtil::Init();
		Misc::Init();
	}
}