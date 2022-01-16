#include "jcinit.h"
#include "api.h"

namespace jc
{
	void init(const SKSE::LoadInterface* a_skse)
	{
		api::init(a_skse);
	}
}