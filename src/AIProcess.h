#pragma once

namespace Gotobed
{
	class Actor;

	class AIProcess : public RE::AIProcess
	{
	public:
		void	OnSitSleepStateChange_Orig(Actor* a_actor, std::uint32_t a_newState, RE::RefHandle* a_refHandle, std::int32_t a_marker);
		void	OnSitSleepStateChange_Hook(Actor* a_actor, std::uint32_t a_newState, RE::RefHandle* a_refHandle, std::int32_t a_marker);

		static void	InstallHooks();
	};
}