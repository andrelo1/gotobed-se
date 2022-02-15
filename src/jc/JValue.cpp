#include "JValue.h"
#include "jcapistorage.h"

namespace jc::JValue
{
	using ApiStorage = jc::api::detail::Storage;

	std::int32_t retain(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_tag)
	{
		return ApiStorage::get().JValue_retain(a_domain, a_obj, a_tag);
	}

	std::int32_t release(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_release(a_domain, a_obj);
	}

	std::int32_t releaseAndRetain(void* a_domain, std::int32_t a_previousObject, std::int32_t a_newObject, RE::BSFixedString a_tag)
	{
		return ApiStorage::get().JValue_releaseAndRetain(a_domain, a_previousObject, a_newObject, a_tag);
	}

	void releaseObjectsWithTag(void* a_domain, RE::BSFixedString a_tag)
	{
		ApiStorage::get().JValue_releaseObjectsWithTag(a_domain, a_tag);
	}

	std::int32_t zeroLifetime(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_zeroLifetime(a_domain, a_obj);
	}

	std::int32_t addToPool(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_poolName)
	{
		return ApiStorage::get().JValue_addToPool(a_domain, a_obj, a_poolName);
	}

	void cleanPool(void* a_domain, RE::BSFixedString a_poolName)
	{
		ApiStorage::get().JValue_cleanPool(a_domain, a_poolName);
	}

	std::int32_t shallowCopy(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_shallowCopy(a_domain, a_obj);
	}

	std::int32_t deepCopy(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_deepCopy(a_domain, a_obj);
	}

	bool isExists(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_isExists(a_domain, a_obj);
	}

	bool isArray(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_isArray(a_domain, a_obj);
	}

	bool isMap(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_isMap(a_domain, a_obj);
	}

	bool isFormMap(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_isFormMap(a_domain, a_obj);
	}

	bool isIntegerMap(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_isIntegerMap(a_domain, a_obj);
	}

	bool empty(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_empty(a_domain, a_obj);
	}

	std::int32_t count(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JValue_count(a_domain, a_obj);
	}

	void clear(void* a_domain, std::int32_t a_obj)
	{
		ApiStorage::get().JValue_clear(a_domain, a_obj);
	}

	std::int32_t readFromFile(void* a_domain, RE::BSFixedString a_filePath)
	{
		return ApiStorage::get().JValue_readFromFile(a_domain, a_filePath);
	}

	std::int32_t readFromDirectory(void* a_domain, RE::BSFixedString a_directoryPath, RE::BSFixedString a_extension)
	{
		return ApiStorage::get().JValue_readFromDirectory(a_domain, a_directoryPath, a_extension);
	}

	std::int32_t objectFromPrototype(void* a_domain, RE::BSFixedString a_prototype)
	{
		return ApiStorage::get().JValue_objectFromPrototype(a_domain, a_prototype);
	}

	void writeToFile(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_filePath)
	{
		ApiStorage::get().JValue_writeToFile(a_domain, a_obj, a_filePath);
	}

	bool hasPath(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path)
	{
		return ApiStorage::get().JValue_hasPath(a_domain, a_obj, a_path);
	}

	std::int32_t solvedValueType(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path)
	{
		return ApiStorage::get().JValue_solvedValueType(a_domain, a_obj, a_path);
	}

	float solveFlt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, float a_default)
	{
		return ApiStorage::get().JValue_solveFlt(a_domain, a_obj, a_path, a_default);
	}

	std::int32_t solveInt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_default)
	{
		return ApiStorage::get().JValue_solveInt(a_domain, a_obj, a_path, a_default);
	}

	RE::BSFixedString solveStr(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, RE::BSFixedString a_default)
	{
		return ApiStorage::get().JValue_solveStr(a_domain, a_obj, a_path, a_default);
	}

	std::int32_t solveObj(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_default)
	{
		return ApiStorage::get().JValue_solveObj(a_domain, a_obj, a_path, a_default);
	}

	RE::TESForm* solveForm(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, RE::TESForm* a_default)
	{
		return ApiStorage::get().JValue_solveForm(a_domain, a_obj, a_path, a_default);
	}

	bool solveFltSetter(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JValue_solveFltSetter(a_domain, a_obj, a_path, a_value, a_createMissingKeys);
	}

	bool solveIntSetter(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JValue_solveIntSetter(a_domain, a_obj, a_path, a_value, a_createMissingKeys);
	}

	bool solveStrSetter(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JValue_solveStrSetter(a_domain, a_obj, a_path, a_value, a_createMissingKeys);
	}

	bool solveObjSetter(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JValue_solveObjSetter(a_domain, a_obj, a_path, a_value, a_createMissingKeys);
	}

	bool solveFormSetter(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys)
	{
		return ApiStorage::get().JValue_solveFormSetter(a_domain, a_obj, a_path, a_value, a_createMissingKeys);
	}

	float evalLuaFlt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_luaCode, float a_default)
	{
		return ApiStorage::get().JValue_evalLuaFlt(a_domain, a_obj, a_luaCode, a_default);
	}

	std::int32_t evalLuaInt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_luaCode, std::int32_t a_default)
	{
		return ApiStorage::get().JValue_evalLuaInt(a_domain, a_obj, a_luaCode, a_default);
	}

	RE::BSFixedString evalLuaStr(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_luaCode, RE::BSFixedString a_default)
	{
		return ApiStorage::get().JValue_evalLuaStr(a_domain, a_obj, a_luaCode, a_default);
	}

	std::int32_t evalLuaObj(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_luaCode, std::int32_t a_default)
	{
		return ApiStorage::get().JValue_evalLuaObj(a_domain, a_obj, a_luaCode, a_default);
	}

	RE::TESForm* evalLuaForm(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_luaCode, RE::TESForm* a_default)
	{
		return ApiStorage::get().JValue_evalLuaForm(a_domain, a_obj, a_luaCode, a_default);
	}
}