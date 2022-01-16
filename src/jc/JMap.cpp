#include "JMap.h"
#include "apistorage.h"

namespace jc::JMap
{
	using ApiStorage = jc::api::detail::Storage;

	std::int32_t object(void* a_domain)
	{
		return ApiStorage::get().JMap_object(a_domain);
	}

	std::int32_t getInt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_default)
	{
		return ApiStorage::get().JMap_getInt(a_domain, a_obj, a_key, a_default);
	}

	float getFlt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key, float a_default)
	{
		return ApiStorage::get().JMap_getFlt(a_domain, a_obj, a_key, a_default);
	}

	RE::BSFixedString getStr(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key, RE::BSFixedString a_default)
	{
		return ApiStorage::get().JMap_getStr(a_domain, a_obj, a_key, a_default);
	}

	std::int32_t getObj(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_default)
	{
		return ApiStorage::get().JMap_getObj(a_domain, a_obj, a_key, a_default);
	}

	RE::TESForm* getForm(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key, RE::TESForm* a_default)
	{
		return ApiStorage::get().JMap_getForm(a_domain, a_obj, a_key, a_default);
	}

	void setInt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_value)
	{
		ApiStorage::get().JMap_setInt(a_domain, a_obj, a_key, a_value);
	}

	void setFlt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key, float a_value)
	{
		ApiStorage::get().JMap_setFlt(a_domain, a_obj, a_key, a_value);
	}

	void setStr(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key, RE::BSFixedString a_value)
	{
		ApiStorage::get().JMap_setStr(a_domain, a_obj, a_key, a_value);
	}

	void setObj(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_container)
	{
		ApiStorage::get().JMap_setObj(a_domain, a_obj, a_key, a_container);
	}

	void setForm(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key, RE::TESForm* a_value)
	{
		ApiStorage::get().JMap_setForm(a_domain, a_obj, a_key, a_value);
	}

	bool hasKey(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key)
	{
		return ApiStorage::get().JMap_hasKey(a_domain, a_obj, a_key);
	}

	std::int32_t valueType(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key)
	{
		return ApiStorage::get().JMap_valueType(a_domain, a_obj, a_key);
	}

	std::int32_t allKeys(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JMap_allKeys(a_domain, a_obj);
	}

	std::vector<RE::BSFixedString> allKeysPArray(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JMap_allKeysPArray(a_domain, a_obj);
	}

	std::int32_t allValues(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JMap_allValues(a_domain, a_obj);
	}

	bool removeKey(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_key)
	{
		return ApiStorage::get().JMap_removeKey(a_domain, a_obj, a_key);
	}

	std::int32_t count(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JMap_count(a_domain, a_obj);
	}

	void clear(void* a_domain, std::int32_t a_obj)
	{
		ApiStorage::get().JMap_clear(a_domain, a_obj);
	}

	void addPairs(void* a_domain, std::int32_t a_obj, std::int32_t a_source, bool a_overrideDuplicates)
	{
		ApiStorage::get().JMap_addPairs(a_domain, a_obj, a_source, a_overrideDuplicates);
	}

	RE::BSFixedString nextKey(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_previousKey, RE::BSFixedString a_endKey)
	{
		return ApiStorage::get().JMap_nextKey(a_domain, a_obj, a_previousKey, a_endKey);
	}

	RE::BSFixedString getNthKey(void* a_domain, std::int32_t a_obj, std::int32_t a_keyIndex)
	{
		return ApiStorage::get().JMap_getNthKey(a_domain, a_obj, a_keyIndex);
	}
}