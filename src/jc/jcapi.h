#pragma once

#include "JContainers/src/JContainers/src/jc_interface.h"

namespace jc
{
	namespace api
	{
		void						init();
		const reflection_interface*	getReflectionInterface();
		const domain_interface*		getDomainInterface();
	}
}