#include "JDB.h"
#include "apistorage.h"

namespace jc::JDB
{
	using ApiStorage = jc::api::detail::Storage;

	float solveFlt(void* a_domain, RE::BSFixedString a_path, float a_default)
	{
		return ApiStorage::get().JDB_solveFlt(a_domain, a_path, a_default);
	}

	std::int32_t solveInt(void* a_domain, RE::BSFixedString a_path, std::int32_t a_default)
	{
		return ApiStorage::get().JDB_solveInt(a_domain,a_path, a_default);
	}

	RE::BSFixedString solveStr(void* a_domain, RE::BSFixedString a_path, RE::BSFixedString a_default)
	{
		return ApiStorage::get().JDB_solveStr(a_domain, a_path, a_default);
	}

	std::int32_t solveObj(void* a_domain, RE::BSFixedString a_path, std::int32_t a_default)
	{
		return ApiStorage::get().JDB_solveObj(a_domain, a_path, a_default);
	}

	RE::TESForm* solveForm(void* a_domain, RE::BSFixedString a_path, RE::TESForm* a_default)
	{
		return ApiStorage::get().JDB_solveForm(a_domain, a_path, a_default);
	}

	bool solveFltSetter(void* a_domain, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JDB_solveFltSetter(a_domain, a_path, a_value, a_createMissingKeys);
	}

	bool solveIntSetter(void* a_domain, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JDB_solveIntSetter(a_domain, a_path, a_value, a_createMissingKeys);
	}

	bool solveStrSetter(void* a_domain, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JDB_solveStrSetter(a_domain, a_path, a_value, a_createMissingKeys);
	}

	bool solveObjSetter(void* a_domain, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JDB_solveObjSetter(a_domain, a_path, a_value, a_createMissingKeys);
	}
	bool solveFormSetter(void* a_domain, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JDB_solveFormSetter(a_domain, a_path, a_value, a_createMissingKeys);
	}

	void setObj(void* a_domain, RE::BSFixedString a_key, std::int32_t a_obj)
	{
		ApiStorage::get().JDB_setObj(a_domain, a_key, a_obj);
	}

	bool hasPath(void* a_domain, RE::BSFixedString a_path)
	{
		return ApiStorage::get().JDB_hasPath(a_domain, a_path);
	}

	std::int32_t allKeys(void* a_domain)
	{
		return ApiStorage::get().JDB_allKeys(a_domain);
	}

	std::int32_t allValues(void* a_domain)
	{
		return ApiStorage::get().JDB_allValues(a_domain);
	}

	void writeToFile(void* a_domain, RE::BSFixedString a_path)
	{
		ApiStorage::get().JDB_writeToFile(a_domain, a_path);
	}

	void readFromFile(void* a_domain, RE::BSFixedString a_path)
	{
		ApiStorage::get().JDB_readFromFile(a_domain, a_path);
	}

	std::int32_t root(void* a_domain)
	{
		return ApiStorage::get().JDB_root(a_domain);
	}
}