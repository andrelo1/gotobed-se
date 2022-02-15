#include "JFormDB.h"
#include "jcapistorage.h"

namespace jc::JFormDB
{
	using ApiStorage = jc::api::detail::Storage;

	void setEntry(void* a_domain, RE::BSFixedString a_storageName, RE::TESForm* a_fKey, std::int32_t a_entry)
	{
		ApiStorage::get().JFormDB_setEntry(a_domain, a_storageName, a_fKey, a_entry);
	}

	std::int32_t makeEntry(void* a_domain, RE::BSFixedString a_storageName, RE::TESForm* a_fKey)
	{
		return ApiStorage::get().JFormDB_makeEntry(a_domain, a_storageName, a_fKey);
	}

	std::int32_t findEntry(void* a_domain, RE::BSFixedString a_storageName, RE::TESForm* a_fKey)
	{
		return ApiStorage::get().JFormDB_findEntry(a_domain, a_storageName, a_fKey);
	}

	float solveFlt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, float a_default)
	{
		return ApiStorage::get().JFormDB_solveFlt(a_domain, a_fKey, a_path, a_default);
	}

	std::int32_t solveInt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_default)
	{
		return ApiStorage::get().JFormDB_solveInt(a_domain, a_fKey, a_path, a_default);
	}

	RE::BSFixedString solveStr(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::BSFixedString a_default)
	{
		return ApiStorage::get().JFormDB_solveStr(a_domain, a_fKey, a_path, a_default);
	}

	std::int32_t solveObj(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_default)
	{
		return ApiStorage::get().JFormDB_solveObj(a_domain, a_fKey, a_path, a_default);
	}

	RE::TESForm* solveForm(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::TESForm* a_default)
	{
		return ApiStorage::get().JFormDB_solveForm(a_domain, a_fKey, a_path, a_default);
	}

	bool solveFltSetter(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JFormDB_solveFltSetter(a_domain, a_fKey, a_path, a_value, a_createMissingKeys);
	}

	bool solveIntSetter(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JFormDB_solveIntSetter(a_domain, a_fKey, a_path, a_value, a_createMissingKeys);
	}

	bool solveStrSetter(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JFormDB_solveStrSetter(a_domain, a_fKey, a_path, a_value, a_createMissingKeys);
	}

	bool solveObjSetter(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JFormDB_solveObjSetter(a_domain, a_fKey, a_path, a_value, a_createMissingKeys);
	}

	bool solveFormSetter(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JFormDB_solveFormSetter(a_domain, a_fKey, a_path, a_value, a_createMissingKeys);
	}

	bool hasPath(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path)
	{
		return ApiStorage::get().JFormDB_hasPath(a_domain, a_fKey, a_path);
	}

	std::int32_t allKeys(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key)
	{
		return ApiStorage::get().JFormDB_allKeys(a_domain, a_fKey, a_key);
	}

	std::int32_t allValues(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key)
	{
		return ApiStorage::get().JFormDB_allValues(a_domain, a_fKey, a_key);
	}

	std::int32_t getInt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key)
	{
		return ApiStorage::get().JFormDB_getInt(a_domain, a_fKey, a_key);
	}

	float getFlt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key)
	{
		return ApiStorage::get().JFormDB_getFlt(a_domain, a_fKey, a_key);
	}

	RE::BSFixedString getStr(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key)
	{
		return ApiStorage::get().JFormDB_getStr(a_domain, a_fKey, a_key);
	}

	std::int32_t getObj(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key)
	{
		return ApiStorage::get().JFormDB_getObj(a_domain, a_fKey, a_key);
	}

	RE::TESForm* getForm(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key)
	{
		return ApiStorage::get().JFormDB_getForm(a_domain, a_fKey, a_key);
	}

	void setInt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key, std::int32_t a_value)
	{
		ApiStorage::get().JFormDB_setInt(a_domain, a_fKey, a_key, a_value);
	}

	void setFlt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key, float a_value)
	{
		ApiStorage::get().JFormDB_setFlt(a_domain, a_fKey, a_key, a_value);
	}

	void setStr(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key, RE::BSFixedString a_value)
	{
		ApiStorage::get().JFormDB_setStr(a_domain, a_fKey, a_key, a_value);
	}

	void setObj(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key, std::int32_t a_container)
	{
		ApiStorage::get().JFormDB_setObj(a_domain, a_fKey, a_key, a_container);
	}

	void setForm(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key, RE::TESForm* a_value)
	{
		ApiStorage::get().JFormDB_setForm(a_domain, a_fKey, a_key, a_value);
	}

}