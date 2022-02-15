#pragma once

namespace jc
{
	struct reflection_interface;
	struct domain_interface;

	namespace api
	{
		void						init();
		const reflection_interface*	getReflectionInterface();
		const domain_interface*		getDomainInterface();
	}
}