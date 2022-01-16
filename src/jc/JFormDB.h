#pragma once

namespace jc::JFormDB
{
	void				setEntry(void* a_domain, RE::BSFixedString a_storageName, RE::TESForm* a_fKey, std::int32_t a_entry);
	std::int32_t		makeEntry(void* a_domain, RE::BSFixedString a_storageName, RE::TESForm* a_fKey);
	std::int32_t		findEntry(void* a_domain, RE::BSFixedString a_storageName, RE::TESForm* a_fKey);
	float				solveFlt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, float a_default = 0.0f);
	std::int32_t		solveInt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_default = 0);
	RE::BSFixedString	solveStr(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::BSFixedString a_default = "");
	std::int32_t		solveObj(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_default = 0);
	RE::TESForm*		solveForm(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::TESForm* a_default = nullptr);
	bool				solveFltSetter(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys = false);
	bool				solveIntSetter(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
	bool				solveStrSetter(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys = false);
	bool				solveObjSetter(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
	bool				solveFormSetter(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys = false);
	bool				hasPath(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_path);
	std::int32_t		allKeys(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key);
	std::int32_t		allValues(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key);
	std::int32_t		getInt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key);
	float				getFlt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key);
	RE::BSFixedString	getStr(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key);
	std::int32_t		getObj(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key);
	RE::TESForm*		getForm(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key);
	void				setInt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key, std::int32_t a_value);
	void				setFlt(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key, float a_value);
	void				setStr(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key, RE::BSFixedString a_value);
	void				setObj(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key, std::int32_t a_container);
	void				setForm(void* a_domain, RE::TESForm* a_fKey, RE::BSFixedString a_key, RE::TESForm* a_value);
}