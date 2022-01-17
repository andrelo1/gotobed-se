#include "ExtraUsedMarkers.h"

namespace Gotobed
{
	ExtraUsedMarkers::Entry* ExtraUsedMarkers::GetMarker(std::uint32_t a_marker)
	{
		for (auto& entry : entries) {
			if (entry.marker == a_marker) {
				return &entry;
			}
		}

		return nullptr;
	}
}