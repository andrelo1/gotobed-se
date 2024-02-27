#pragma once

namespace Gotobed {
	class TESObjectREFR: public RE::TESObjectREFR
	{
	public:
		bool	SetMarkerReserved_Orig(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed);
		bool	SetMarkerReserved_Hook(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed);

		static void	InstallHooks();
	};
}