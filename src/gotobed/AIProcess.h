#pragma once

namespace Gotobed
{
	class AIProcess : public RE::AIProcess
	{
	public:
		void	OnSitSleepStateChange(RE::Actor* a_actor, std::uint32_t a_newState, RE::RefHandle& a_refHandle, std::int32_t a_marker);
		void	OnSitSleepStateChangeHook(RE::Actor* a_actor, std::uint32_t a_newState, RE::RefHandle& a_refHandle, std::int32_t a_marker);
	};

	namespace AIProcessNS
	{
		void	Init();
	}
}