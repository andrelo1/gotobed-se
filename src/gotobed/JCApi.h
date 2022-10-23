#pragma once

namespace jc
{
	namespace api
	{
		void	init(std::function<void(bool)> a_onInitComplete = nullptr);
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
		std::int32_t		solveObj(RE::BSFixedString a_path, std::int32_t a_default = 0);
		RE::TESForm*		solveForm(RE::BSFixedString a_path, RE::TESForm* a_default = nullptr);
		bool				solveFltSetter(RE::BSFixedString a_path, float a_value, bool a_createMissingKeys = false);
		bool				solveIntSetter(RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
		bool				solveStrSetter(RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys = false);
		bool				solveObjSetter(RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
		bool				solveFormSetter(RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys = false);
		void				setObj(RE::BSFixedString a_key, std::int32_t a_obj);
		bool				hasPath(RE::BSFixedString a_path);
		std::int32_t		allKeys();
		std::int32_t		allValues();
		void				writeToFile(RE::BSFixedString a_path);
		//void				readFromFile(RE::BSFixedString a_path);
		std::int32_t		root();
	}

	namespace JFormDB
	{
		void				setEntry(RE::BSFixedString a_storageName, RE::TESForm* a_fKey, std::int32_t a_entry);
		std::int32_t		makeEntry(RE::BSFixedString a_storageName, RE::TESForm* a_fKey);
		std::int32_t		findEntry(RE::BSFixedString a_storageName, RE::TESForm* a_fKey);
		float				solveFlt(RE::TESForm* a_fKey, RE::BSFixedString a_path, float a_default = 0.0f);
		std::int32_t		solveInt(RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_default = 0);
		RE::BSFixedString	solveStr(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::BSFixedString a_default = "");
		std::int32_t		solveObj(RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_default = 0);
		RE::TESForm*		solveForm(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::TESForm* a_default = nullptr);
		bool				solveFltSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys = false);
		bool				solveIntSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
		bool				solveStrSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys = false);
		bool				solveObjSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
		bool				solveFormSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys = false);
		bool				hasPath(RE::TESForm* a_fKey, RE::BSFixedString a_path);
		std::int32_t		allKeys(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		std::int32_t		allValues(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		std::int32_t		getInt(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		float				getFlt(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		RE::BSFixedString	getStr(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		std::int32_t		getObj(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		RE::TESForm*		getForm(RE::TESForm* a_fKey, RE::BSFixedString a_key);
		void				setInt(RE::TESForm* a_fKey, RE::BSFixedString a_key, std::int32_t a_value);
		void				setFlt(RE::TESForm* a_fKey, RE::BSFixedString a_key, float a_value);
		void				setStr(RE::TESForm* a_fKey, RE::BSFixedString a_key, RE::BSFixedString a_value);
		void				setObj(RE::TESForm* a_fKey, RE::BSFixedString a_key, std::int32_t a_container);
		void				setForm(RE::TESForm* a_fKey, RE::BSFixedString a_key, RE::TESForm* a_value);
	}

	namespace JValue
	{
		std::int32_t		retain(std::int32_t a_obj, RE::BSFixedString a_tag = "");
		std::int32_t		release(std::int32_t a_obj);
		std::int32_t		releaseAndRetain(std::int32_t a_previousObject, std::int32_t a_newObject, RE::BSFixedString a_tag = "");
		void				releaseObjectsWithTag(RE::BSFixedString a_tag);
		std::int32_t		zeroLifetime(std::int32_t a_obj);
		std::int32_t		addToPool(std::int32_t a_obj, RE::BSFixedString a_poolName);
		void				cleanPool(RE::BSFixedString a_poolName);
		std::int32_t		shallowCopy(std::int32_t a_obj);
		std::int32_t		deepCopy(std::int32_t a_obj);
		bool				isExists(std::int32_t a_obj);
		bool				isArray(std::int32_t a_obj);
		bool				isMap(std::int32_t a_obj);
		bool				isFormMap(std::int32_t a_obj);
		bool				isIntegerMap(std::int32_t a_obj);
		bool				empty(std::int32_t a_obj);
		std::int32_t		count(std::int32_t a_obj);
		void				clear(std::int32_t a_obj);
		std::int32_t		readFromFile(RE::BSFixedString a_filePath);
		std::int32_t		readFromDirectory(RE::BSFixedString a_directoryPath, RE::BSFixedString a_extension = "");
		std::int32_t		objectFromPrototype(RE::BSFixedString a_prototype);
		void				writeToFile(std::int32_t a_obj, RE::BSFixedString a_filePath);
		bool				hasPath(std::int32_t a_obj, RE::BSFixedString a_path);
		std::int32_t		solvedValueType(std::int32_t a_obj, RE::BSFixedString a_path);
		float				solveFlt(std::int32_t a_obj, RE::BSFixedString a_path, float a_default = 0.0f);
		std::int32_t		solveInt(std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_default = 0);
		RE::BSFixedString	solveStr(std::int32_t a_obj, RE::BSFixedString a_path, RE::BSFixedString a_default = "");
		std::int32_t		solveObj(std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_default = 0);
		RE::TESForm*		solveForm(std::int32_t a_obj, RE::BSFixedString a_path, RE::TESForm* a_default = nullptr);
		bool				solveFltSetter(std::int32_t a_obj, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys = false);
		bool				solveIntSetter(std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
		bool				solveStrSetter(std::int32_t a_obj, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys = false);
		bool				solveObjSetter(std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
		bool				solveFormSetter(std::int32_t a_obj, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys = false);
		float				evalLuaFlt(std::int32_t a_obj, RE::BSFixedString a_luaCode, float a_default = 0.0f);
		std::int32_t		evalLuaInt(std::int32_t a_obj, RE::BSFixedString a_luaCode, std::int32_t a_default = 0);
		RE::BSFixedString	evalLuaStr(std::int32_t a_obj, RE::BSFixedString a_luaCode, RE::BSFixedString a_default = "");
		std::int32_t		evalLuaObj(std::int32_t a_obj, RE::BSFixedString a_luaCode, std::int32_t a_default = 0);
		RE::TESForm*		evalLuaForm(std::int32_t a_obj, RE::BSFixedString a_luaCode, RE::TESForm* a_default = nullptr);
	}

	namespace JArray
	{
		std::int32_t		object();
		std::int32_t		objectWithSize(std::int32_t a_size);
		std::int32_t		objectWithInts(RE::BSTSmartPointer<RE::BSScript::Array> a_values);
		std::int32_t		objectWithStrings(RE::BSTSmartPointer<RE::BSScript::Array> a_values);
		std::int32_t		objectWithFloats(RE::BSTSmartPointer<RE::BSScript::Array> a_values);
		std::int32_t		objectWithBooleans(RE::BSTSmartPointer<RE::BSScript::Array> a_values);
		std::int32_t		objectWithForms(RE::BSTSmartPointer<RE::BSScript::Array> a_values);
		std::int32_t		subArray(std::int32_t a_obj, std::int32_t a_startIndex, std::int32_t a_endIndex);
		void				addFromArray(std::int32_t a_obj, std::int32_t a_source, std::int32_t a_insertAtIndex = -1);
		void				addFromFormList(std::int32_t a_obj, RE::BGSListForm* a_source, std::int32_t a_insertAtIndex = -1);
		std::int32_t		getInt(std::int32_t a_obj, std::int32_t a_index, std::int32_t a_default = 0);
		float				getFlt(std::int32_t a_obj, std::int32_t a_index, float a_default = 0.0f);
		RE::BSFixedString	getStr(std::int32_t a_obj, std::int32_t a_index, RE::BSFixedString a_default = "");
		std::int32_t		getObj(std::int32_t a_obj, std::int32_t a_index, std::int32_t a_default = 0);
		RE::TESForm*		getForm(std::int32_t a_obj, std::int32_t a_index, RE::TESForm* a_default = nullptr);
		std::int32_t		findInt(std::int32_t a_obj, std::int32_t a_value, std::int32_t a_searchStartIndex = 0);
		std::int32_t		findFlt(std::int32_t a_obj, float a_value, std::int32_t a_searchStartIndex = 0);
		std::int32_t		findStr(std::int32_t a_obj, RE::BSFixedString a_value, std::int32_t a_searchStartIndex = 0);
		std::int32_t		findObj(std::int32_t a_obj, std::int32_t a_value, std::int32_t a_searchStartIndex = 0);
		std::int32_t		findForm(std::int32_t a_obj, RE::TESForm* a_value, std::int32_t a_searchStartIndex = 0);
		void				setInt(std::int32_t a_obj, std::int32_t a_index, std::int32_t a_value);
		void				setFlt(std::int32_t a_obj, std::int32_t a_index, float a_value);
		void				setStr(std::int32_t a_obj, std::int32_t a_index, RE::BSFixedString a_value);
		void				setObj(std::int32_t a_obj, std::int32_t a_index, std::int32_t a_value);
		void				setForm(std::int32_t a_obj, std::int32_t a_index, RE::TESForm* a_value);
		void				addInt(std::int32_t a_obj, std::int32_t a_value, std::int32_t a_index = -1);
		void				addFlt(std::int32_t a_obj, float a_value, std::int32_t a_index = -1);
		void				addStr(std::int32_t a_obj, RE::BSFixedString a_value, std::int32_t a_index = -1);
		void				addObj(std::int32_t a_obj, std::int32_t a_value, std::int32_t a_index = -1);
		void				addForm(std::int32_t a_obj, RE::TESForm* a_value, std::int32_t a_index = -1);
		std::int32_t		count(std::int32_t a_obj);
		void				clear(std::int32_t a_obj);
		void				eraseIndex(std::int32_t a_obj, std::int32_t a_index);
		void				eraseRange(std::int32_t a_obj, std::int32_t a_first, std::int32_t a_last);
		std::int32_t		valueType(std::int32_t a_obj, std::int32_t a_index);
		void				swapItems(std::int32_t a_obj, std::int32_t a_index1, std::int32_t a_index2);
		std::int32_t		sort(std::int32_t a_obj);
		std::int32_t		unique(std::int32_t a_obj);
		bool				writeToIntegerPArray(std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, std::int32_t a_defaultRead = 0);
		bool				writeToFloatPArray(std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, float a_defaultRead = 0.0f);
		bool				writeToFormPArray(std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, RE::TESForm* a_defaultRead = nullptr);
		bool				writeToStringPArray(std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, RE::BSFixedString a_defaultRead = "");
	}

	namespace JMap
	{
		std::int32_t		object();
		std::int32_t		getInt(std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_default = 0);
		float				getFlt(std::int32_t a_obj, RE::BSFixedString a_key, float a_default = 0.0f);
		RE::BSFixedString	getStr(std::int32_t a_obj, RE::BSFixedString a_key, RE::BSFixedString a_default = "");
		std::int32_t		getObj(std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_default = 0);
		RE::TESForm*		getForm(std::int32_t a_obj, RE::BSFixedString a_key, RE::TESForm* a_default = nullptr);
		void				setInt(std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_value);
		void				setFlt(std::int32_t a_obj, RE::BSFixedString a_key, float a_value);
		void				setStr(std::int32_t a_obj, RE::BSFixedString a_key, RE::BSFixedString a_value);
		void				setObj(std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_container);
		void				setForm(std::int32_t a_obj, RE::BSFixedString a_key, RE::TESForm* a_value);
		bool				hasKey(std::int32_t a_obj, RE::BSFixedString a_key);
		std::int32_t		valueType(std::int32_t a_obj, RE::BSFixedString a_key);
		std::int32_t		allKeys(std::int32_t a_obj);
		std::vector<RE::BSFixedString>	allKeysPArray(std::int32_t a_obj);
		std::int32_t		allValues(std::int32_t a_obj);
		bool				removeKey(std::int32_t a_obj, RE::BSFixedString a_key);
		std::int32_t		count(std::int32_t a_obj);
		void				clear(std::int32_t a_obj);
		void				addPairs(std::int32_t a_obj, std::int32_t a_source, bool a_overrideDuplicates);
		RE::BSFixedString	nextKey(std::int32_t a_obj, RE::BSFixedString a_previousKey = "", RE::BSFixedString a_endKey = "");
		RE::BSFixedString	getNthKey(std::int32_t a_obj, std::int32_t a_keyIndex);
	}
}