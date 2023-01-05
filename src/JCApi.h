#pragma once

#include "JCTypes.h"

namespace jc
{
	namespace api
	{
		bool	ready();
		void	init(std::function<void()> a_onInitComplete = {});
		void*	getDefaultDomain();
		bool	setDefaultDomain(const char* a_name = "");
	}

	namespace domain
	{
		void* get(const char* a_name = "");
	}

	namespace JDB
	{
		float				solveFlt(RE::BSFixedString a_path, float a_default = 0.0f);
		std::int32_t		solveInt(RE::BSFixedString a_path, std::int32_t a_default = 0);
		RE::BSFixedString	solveStr(RE::BSFixedString a_path, RE::BSFixedString a_default = "");
		Handle				solveObj(RE::BSFixedString a_path, Handle a_default = Handle::Null);
		RE::TESForm*		solveForm(RE::BSFixedString a_path, RE::TESForm* a_default = nullptr);
		bool				solveFltSetter(RE::BSFixedString a_path, float a_value, bool a_createMissingKeys = false);
		bool				solveIntSetter(RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
		bool				solveStrSetter(RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys = false);
		bool				solveObjSetter(RE::BSFixedString a_path, Handle a_value, bool a_createMissingKeys = false);
		bool				solveFormSetter(RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys = false);
		void				setObj(RE::BSFixedString a_key, Handle a_obj);
		bool				hasPath(RE::BSFixedString a_path);
		Handle				allKeys();
		Handle				allValues();
		void				writeToFile(RE::BSFixedString a_path);
		//void				readFromFile(RE::BSFixedString a_path);
		Handle				root();
	}

	namespace JFormDB
	{
		void				setEntry(RE::BSFixedString a_storageName, RE::TESForm* a_fKey, Handle a_entry);
		Handle				makeEntry(RE::BSFixedString a_storageName, RE::TESForm* a_fKey);
		Handle				findEntry(RE::BSFixedString a_storageName, RE::TESForm* a_fKey);
		float				solveFlt(RE::TESForm* a_fKey, RE::BSFixedString a_path, float a_default = 0.0f);
		Handle				solveInt(RE::TESForm* a_fKey, RE::BSFixedString a_path, Handle a_default = Handle::Null);
		RE::BSFixedString	solveStr(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::BSFixedString a_default = "");
		Handle				solveObj(RE::TESForm* a_fKey, RE::BSFixedString a_path, Handle a_default = Handle::Null);
		RE::TESForm*		solveForm(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::TESForm* a_default = nullptr);
		bool				solveFltSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys = false);
		bool				solveIntSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
		bool				solveStrSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys = false);
		bool				solveObjSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, Handle a_value, bool a_createMissingKeys = false);
		bool				solveFormSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys = false);
		bool				hasPath(RE::TESForm* a_fKey, RE::BSFixedString a_path);
		Handle				allKeys(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		Handle				allValues(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		std::int32_t		getInt(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		float				getFlt(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		RE::BSFixedString	getStr(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		Handle				getObj(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		RE::TESForm*		getForm(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		void				setInt(RE::TESForm* a_fKey, RE::BSFixedString a_key, std::int32_t a_value);
		void				setFlt(RE::TESForm* a_fKey, RE::BSFixedString a_key, float a_value);
		void				setStr(RE::TESForm* a_fKey, RE::BSFixedString a_key, RE::BSFixedString a_value);
		void				setObj(RE::TESForm* a_fKey, RE::BSFixedString a_key, Handle a_container);
		void				setForm(RE::TESForm* a_fKey, RE::BSFixedString a_key, RE::TESForm* a_value);
	}

	namespace JValue
	{
		Handle				retain(Handle a_obj, RE::BSFixedString a_tag = "");
		Handle				release(Handle a_obj);
		Handle				releaseAndRetain(Handle a_previousObject, Handle a_newObject, RE::BSFixedString a_tag = "");
		void				releaseObjectsWithTag(RE::BSFixedString a_tag);
		Handle				zeroLifetime(Handle a_obj);
		Handle				addToPool(Handle a_obj, RE::BSFixedString a_poolName);
		void				cleanPool(RE::BSFixedString a_poolName);
		Handle				shallowCopy(Handle a_obj);
		Handle				deepCopy(Handle a_obj);
		bool				isExists(Handle a_obj);
		bool				isArray(Handle a_obj);
		bool				isMap(Handle a_obj);
		bool				isFormMap(Handle a_obj);
		bool				isIntegerMap(Handle a_obj);
		bool				empty(Handle a_obj);
		std::int32_t		count(Handle a_obj);
		void				clear(Handle a_obj);
		Handle				readFromFile(RE::BSFixedString a_filePath);
		Handle				readFromDirectory(RE::BSFixedString a_directoryPath, RE::BSFixedString a_extension = "");
		Handle				objectFromPrototype(RE::BSFixedString a_prototype);
		void				writeToFile(Handle a_obj, RE::BSFixedString a_filePath);
		bool				hasPath(Handle a_obj, RE::BSFixedString a_path);
		std::int32_t		solvedValueType(Handle a_obj, RE::BSFixedString a_path);
		float				solveFlt(Handle a_obj, RE::BSFixedString a_path, float a_default = 0.0f);
		std::int32_t		solveInt(Handle a_obj, RE::BSFixedString a_path, std::int32_t a_default = 0);
		RE::BSFixedString	solveStr(Handle a_obj, RE::BSFixedString a_path, RE::BSFixedString a_default = "");
		Handle				solveObj(Handle a_obj, RE::BSFixedString a_path, Handle a_default = Handle::Null);
		RE::TESForm*		solveForm(Handle a_obj, RE::BSFixedString a_path, RE::TESForm* a_default = nullptr);
		bool				solveFltSetter(Handle a_obj, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys = false);
		bool				solveIntSetter(Handle a_obj, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
		bool				solveStrSetter(Handle a_obj, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys = false);
		bool				solveObjSetter(Handle a_obj, RE::BSFixedString a_path, Handle a_value, bool a_createMissingKeys = false);
		bool				solveFormSetter(Handle a_obj, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys = false);
		float				evalLuaFlt(Handle a_obj, RE::BSFixedString a_luaCode, float a_default = 0.0f);
		std::int32_t		evalLuaInt(Handle a_obj, RE::BSFixedString a_luaCode, std::int32_t a_default = 0);
		RE::BSFixedString	evalLuaStr(Handle a_obj, RE::BSFixedString a_luaCode, RE::BSFixedString a_default = "");
		Handle				evalLuaObj(Handle a_obj, RE::BSFixedString a_luaCode, Handle a_default = Handle::Null);
		RE::TESForm*		evalLuaForm(Handle a_obj, RE::BSFixedString a_luaCode, RE::TESForm* a_default = nullptr);
	}

	namespace JArray
	{
		Handle				object();
		Handle				objectWithSize(std::int32_t a_size);
		Handle				objectWithInts(RE::BSTSmartPointer<RE::BSScript::Array> a_values);
		Handle				objectWithStrings(RE::BSTSmartPointer<RE::BSScript::Array> a_values);
		Handle				objectWithFloats(RE::BSTSmartPointer<RE::BSScript::Array> a_values);
		Handle				objectWithBooleans(RE::BSTSmartPointer<RE::BSScript::Array> a_values);
		Handle				objectWithForms(RE::BSTSmartPointer<RE::BSScript::Array> a_values);
		Handle				subArray(Handle a_obj, std::int32_t a_startIndex, std::int32_t a_endIndex);
		void				addFromArray(Handle a_obj, Handle a_source, std::int32_t a_insertAtIndex = -1);
		void				addFromFormList(Handle a_obj, RE::BGSListForm* a_source, std::int32_t a_insertAtIndex = -1);
		std::int32_t		getInt(Handle a_obj, std::int32_t a_index, std::int32_t a_default = 0);
		float				getFlt(Handle a_obj, std::int32_t a_index, float a_default = 0.0f);
		RE::BSFixedString	getStr(Handle a_obj, std::int32_t a_index, RE::BSFixedString a_default = "");
		Handle				getObj(Handle a_obj, std::int32_t a_index, Handle a_default = Handle::Null);
		RE::TESForm*		getForm(Handle a_obj, std::int32_t a_index, RE::TESForm* a_default = nullptr);
		std::int32_t		findInt(Handle a_obj, std::int32_t a_value, std::int32_t a_searchStartIndex = 0);
		std::int32_t		findFlt(Handle a_obj, float a_value, std::int32_t a_searchStartIndex = 0);
		std::int32_t		findStr(Handle a_obj, RE::BSFixedString a_value, std::int32_t a_searchStartIndex = 0);
		std::int32_t		findObj(Handle a_obj, Handle a_value, std::int32_t a_searchStartIndex = 0);
		std::int32_t		findForm(Handle a_obj, RE::TESForm* a_value, std::int32_t a_searchStartIndex = 0);
		void				setInt(Handle a_obj, std::int32_t a_index, std::int32_t a_value);
		void				setFlt(Handle a_obj, std::int32_t a_index, float a_value);
		void				setStr(Handle a_obj, std::int32_t a_index, RE::BSFixedString a_value);
		void				setObj(Handle a_obj, std::int32_t a_index, Handle a_value);
		void				setForm(Handle a_obj, std::int32_t a_index, RE::TESForm* a_value);
		void				addInt(Handle a_obj, std::int32_t a_value, std::int32_t a_index = -1);
		void				addFlt(Handle a_obj, float a_value, std::int32_t a_index = -1);
		void				addStr(Handle a_obj, RE::BSFixedString a_value, std::int32_t a_index = -1);
		void				addObj(Handle a_obj, Handle a_value, std::int32_t a_index = -1);
		void				addForm(Handle a_obj, RE::TESForm* a_value, std::int32_t a_index = -1);
		std::int32_t		count(Handle a_obj);
		void				clear(Handle a_obj);
		void				eraseIndex(Handle a_obj, std::int32_t a_index);
		void				eraseRange(Handle a_obj, std::int32_t a_first, std::int32_t a_last);
		std::int32_t		valueType(Handle a_obj, std::int32_t a_index);
		void				swapItems(Handle a_obj, std::int32_t a_index1, std::int32_t a_index2);
		Handle				sort(Handle a_obj);
		Handle				unique(Handle a_obj);
		bool				writeToIntegerPArray(Handle a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, std::int32_t a_defaultRead = 0);
		bool				writeToFloatPArray(Handle a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, float a_defaultRead = 0.0f);
		bool				writeToFormPArray(Handle a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, RE::TESForm* a_defaultRead = nullptr);
		bool				writeToStringPArray(Handle a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, RE::BSFixedString a_defaultRead = "");
	}

	namespace JMap
	{
		Handle				object();
		std::int32_t		getInt(Handle a_obj, RE::BSFixedString a_key, std::int32_t a_default = 0);
		float				getFlt(Handle a_obj, RE::BSFixedString a_key, float a_default = 0.0f);
		RE::BSFixedString	getStr(Handle a_obj, RE::BSFixedString a_key, RE::BSFixedString a_default = "");
		Handle				getObj(Handle a_obj, RE::BSFixedString a_key, Handle a_default = Handle::Null);
		RE::TESForm*		getForm(Handle a_obj, RE::BSFixedString a_key, RE::TESForm* a_default = nullptr);
		void				setInt(Handle a_obj, RE::BSFixedString a_key, std::int32_t a_value);
		void				setFlt(Handle a_obj, RE::BSFixedString a_key, float a_value);
		void				setStr(Handle a_obj, RE::BSFixedString a_key, RE::BSFixedString a_value);
		void				setObj(Handle a_obj, RE::BSFixedString a_key, Handle a_container);
		void				setForm(Handle a_obj, RE::BSFixedString a_key, RE::TESForm* a_value);
		bool				hasKey(Handle a_obj, RE::BSFixedString a_key);
		std::int32_t		valueType(Handle a_obj, RE::BSFixedString a_key);
		Handle				allKeys(Handle a_obj);
		std::vector<RE::BSFixedString>	allKeysPArray(Handle a_obj);
		Handle				allValues(Handle a_obj);
		bool				removeKey(Handle a_obj, RE::BSFixedString a_key);
		std::int32_t		count(Handle a_obj);
		void				clear(Handle a_obj);
		void				addPairs(Handle a_obj, Handle a_source, bool a_overrideDuplicates);
		RE::BSFixedString	nextKey(Handle a_obj, RE::BSFixedString a_previousKey = "", RE::BSFixedString a_endKey = "");
		RE::BSFixedString	getNthKey(Handle a_obj, std::int32_t a_keyIndex);
	}
}