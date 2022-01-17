#include "ExtraReservedMarkers.h"

namespace Gotobed
{	
	ExtraReservedMarkers::Entry* ExtraReservedMarkers::GetMarker(std::uint32_t a_marker)
	{
		for (auto& entry : entries) {
			if (entry.marker == a_marker) {
				return &entry;
			}
		}

		return nullptr;
	}
}