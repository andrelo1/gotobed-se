#include "gotobedinit.h"
#include "TESObjectREFR.h"
#include "Misc.h"
#include "MenuOpenHandler.h"
#include "AIProcess.h"

namespace Gotobed
{
	void Init()
	{
		MenuOpenHandlerNS::Init();
		AIProcessNS::Init();
		TESObjectREFRNS::Init();
		Misc::Init();
	}
}