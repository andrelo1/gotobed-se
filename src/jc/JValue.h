#pragma once

namespace jc::JValue
{
	std::int32_t		retain(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_tag = "");
	std::int32_t		release(void* a_domain, std::int32_t a_obj);
	std::int32_t		releaseAndRetain(void* a_domain, std::int32_t a_previousObject, std::int32_t a_newObject, RE::BSFixedString a_tag = "");
	void				releaseObjectsWithTag(void* a_domain, RE::BSFixedString a_tag);
	std::int32_t		zeroLifetime(void* a_domain, std::int32_t a_obj);
	std::int32_t		addToPool(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_poolName);
	void				cleanPool(void* a_domain, RE::BSFixedString a_poolName);
	std::int32_t		shallowCopy(void* a_domain, std::int32_t a_obj);
	std::int32_t		deepCopy(void* a_domain, std::int32_t a_obj);
	bool				isExists(void* a_domain, std::int32_t a_obj);
	bool				isArray(void* a_domain, std::int32_t a_obj);
	bool				isMap(void* a_domain, std::int32_t a_obj);
	bool				isFormMap(void* a_domain, std::int32_t a_obj);
	bool				isIntegerMap(void* a_domain, std::int32_t a_obj);
	bool				empty(void* a_domain, std::int32_t a_obj);
	std::int32_t		count(void* a_domain, std::int32_t a_obj);
	void				clear(void* a_domain, std::int32_t a_obj);
	std::int32_t		readFromFile(void* a_domain, RE::BSFixedString a_filePath);
	std::int32_t		readFromDirectory(void* a_domain, RE::BSFixedString a_directoryPath, RE::BSFixedString a_extension = "");
	std::int32_t		objectFromPrototype(void* a_domain, RE::BSFixedString a_prototype);
	void				writeToFile(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_filePath);
	bool				hasPath(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path);
	std::int32_t		solvedValueType(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path);
	float				solveFlt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, float a_default = 0.0f);
	std::int32_t		solveInt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_default = 0);
	RE::BSFixedString	solveStr(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, RE::BSFixedString a_default = "");
	std::int32_t		solveObj(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_default = 0);
	RE::TESForm*		solveForm(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, RE::TESForm* a_default = nullptr);
	bool				solveFltSetter(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys = false);
	bool				solveIntSetter(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
	bool				solveStrSetter(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys = false);
	bool				solveObjSetter(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
	bool				solveFormSetter(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys = false);
	float				evalLuaFlt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_luaCode, float a_default = 0.0f);
	std::int32_t		evalLuaInt(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_luaCode, std::int32_t a_default = 0);
	RE::BSFixedString	evalLuaStr(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_luaCode, RE::BSFixedString a_default = "");
	std::int32_t		evalLuaObj(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_luaCode, std::int32_t a_default = 0);
	RE::TESForm*		evalLuaForm(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_luaCode, RE::TESForm* a_default = nullptr);
}