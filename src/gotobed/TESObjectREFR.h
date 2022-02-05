#pragma once

namespace Gotobed
{
	class TESObjectREFR : public RE::TESObjectREFR
	{
	public:
		bool	SetMarkerReserved_Hook(std::uint32_t a_marker, RE::Actor* a_actor, bool a_reserved, bool a_ignoreUsed);
		bool	SetMarkerUsed_Hook(std::uint32_t a_marker, RE::Actor* a_actor, bool a_used, bool a_ignoreReserved);
	};

	namespace TESObjectREFRNS
	{
		void	Init();
	}
}
