#pragma once

namespace jc::domain
{
#ifdef JC_DOMAIN
	void*	get(const char* a_name = JC_DOMAIN);
#else
	void*	get(const char* a_name);
#endif

	void*	getDefault();
}