#pragma once

namespace Gotobed
{
	class ExtraReservedMarkers : public RE::BSExtraData
	{
	public:
		struct Entry
		{
			RE::ActorHandle		actor;	// 0
			std::uint32_t		marker;	// 4
			RE::AITimeStamp		time;	// 8
		};

		static_assert(sizeof(Entry) == 0xC);

		inline static constexpr auto RTTI = RE::RTTI_ExtraReservedMarkers;
		inline static constexpr auto EXTRADATATYPE = RE::ExtraDataType::kReservedMarkers;

		~ExtraReservedMarkers() override;	// 00

		RE::ExtraDataType	GetType() const override;	// 01

		Entry*				GetMarker(std::uint32_t a_marker);

		RE::BSTArray<Entry>			entries;	// 10
		mutable RE::BSReadWriteLock	lock;		// 28
	};

	static_assert(sizeof(ExtraReservedMarkers) == 0x30);
}