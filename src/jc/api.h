#pragma once

namespace jc
{
	struct reflection_interface;
	struct domain_interface;

	namespace api
	{
		void						init(const SKSE::LoadInterface* a_skse);
		const reflection_interface*	getReflectionInterface();
		const domain_interface*		getDomainInterface();
	}
}