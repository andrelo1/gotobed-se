#include "apistorage.h"

namespace jc::api::detail
{
	Storage& Storage::get()
	{
		static Storage storage;
		return storage;
	}
}