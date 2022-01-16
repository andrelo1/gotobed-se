#pragma once

namespace Gotobed
{
	class AIProcess : public RE::AIProcess
	{
	public:
		void	SitSleepStateUpdate(RE::Actor* a_actor, std::uint32_t a_newState, RE::RefHandle& a_refHandle, std::int32_t a_marker);
		void	SitSleepStateUpdate_Hook(RE::Actor* a_actor, std::uint32_t a_newState, RE::RefHandle& a_refHandle, std::int32_t a_marker);
	};

	namespace AIProcessNS
	{
		void	Init();
	}
}