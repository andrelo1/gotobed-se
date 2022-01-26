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
		TESObjectREFRNS::Init();
#ifndef NOJC
		AIProcessNS::Init();
#endif
		UIUtil::Init();
		Misc::Init();
	}
}