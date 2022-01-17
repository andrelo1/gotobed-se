#pragma once

namespace Gotobed
{
	class ExtraUsedMarkers : public RE::BSExtraData
	{
	public:
		struct Entry
		{
			RE::ActorHandle		actor;	// 0
			std::uint32_t		marker;	// 4
			RE::AITimeStamp		time;	// 8
		};

		static_assert(sizeof(Entry) == 0xC);

		inline static constexpr auto RTTI = RE::RTTI_ExtraUsedMarkers;
		inline static constexpr auto EXTRADATATYPE = RE::ExtraDataType::kUsedMarkers;

		~ExtraUsedMarkers() override;	// 00

		RE::ExtraDataType	GetType() const override;	// 01

		Entry*				GetMarker(std::uint32_t a_marker);

		RE::BSTArray<Entry>	entries;	// 10
	};

	static_assert(sizeof(ExtraUsedMarkers) == 0x28);
}