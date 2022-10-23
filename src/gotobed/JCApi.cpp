#include "jcapi.h"
#include "JContainers/src/JContainers/src/jc_interface.h"

namespace jc
{
	namespace api
	{
		namespace detail
		{
			struct Storage
			{
				static Storage& get() {
					static Storage storage;
					return storage;
				}

				const reflection_interface*	reflectionInterface{ nullptr };
				const domain_interface*		domainInterface{ nullptr };
				void*						defaultDomain{ nullptr };
				std::function<void(bool)>	onInitComplete{ nullptr };

				float				(*JDB_solveFlt)(void*, RE::BSFixedString, float) { nullptr };
				std::int32_t		(*JDB_solveInt)(void*, RE::BSFixedString, std::int32_t) { nullptr };
				RE::BSFixedString	(*JDB_solveStr)(void*, RE::BSFixedString, RE::BSFixedString) { nullptr };
				std::int32_t		(*JDB_solveObj)(void*, RE::BSFixedString, std::int32_t) { nullptr };
				RE::TESForm*		(*JDB_solveForm)(void*, RE::BSFixedString, RE::TESForm*) { nullptr };
				bool				(*JDB_solveFltSetter)(void*, RE::BSFixedString, float, bool) { nullptr };
				bool				(*JDB_solveIntSetter)(void*, RE::BSFixedString, std::int32_t, bool) { nullptr };
				bool				(*JDB_solveStrSetter)(void*, RE::BSFixedString, RE::BSFixedString, bool) { nullptr };
				bool				(*JDB_solveObjSetter)(void*, RE::BSFixedString, std::int32_t, bool) { nullptr };
				bool				(*JDB_solveFormSetter)(void*, RE::BSFixedString, RE::TESForm*, bool) { nullptr };
				void				(*JDB_setObj)(void*, RE::BSFixedString, std::int32_t) { nullptr };
				bool				(*JDB_hasPath)(void*, RE::BSFixedString) { nullptr };
				std::int32_t		(*JDB_allKeys)(void*) { nullptr };
				std::int32_t		(*JDB_allValues)(void*) { nullptr };
				void				(*JDB_writeToFile)(void*, RE::BSFixedString) { nullptr };
				void				(*JDB_readFromFile)(void*, RE::BSFixedString) { nullptr };
				std::int32_t		(*JDB_root)(void*) { nullptr };

				void				(*JFormDB_setEntry)(void*, RE::BSFixedString, RE::TESForm*, std::int32_t) { nullptr };
				std::int32_t		(*JFormDB_makeEntry)(void*, RE::BSFixedString, RE::TESForm*) { nullptr };
				std::int32_t		(*JFormDB_findEntry)(void*, RE::BSFixedString, RE::TESForm*) { nullptr };
				float				(*JFormDB_solveFlt)(void*, RE::TESForm*, RE::BSFixedString, float) { nullptr };
				std::int32_t		(*JFormDB_solveInt)(void*, RE::TESForm*, RE::BSFixedString, std::int32_t) { nullptr };
				RE::BSFixedString	(*JFormDB_solveStr)(void*, RE::TESForm*, RE::BSFixedString, RE::BSFixedString) { nullptr };
				std::int32_t		(*JFormDB_solveObj)(void*, RE::TESForm*, RE::BSFixedString, std::int32_t) { nullptr };
				RE::TESForm*		(*JFormDB_solveForm)(void*, RE::TESForm*, RE::BSFixedString, RE::TESForm*) { nullptr };
				bool				(*JFormDB_solveFltSetter)(void*, RE::TESForm*, RE::BSFixedString, float, bool) { nullptr };
				bool				(*JFormDB_solveIntSetter)(void*, RE::TESForm*, RE::BSFixedString, std::int32_t, bool) { nullptr };
				bool				(*JFormDB_solveStrSetter)(void*, RE::TESForm*, RE::BSFixedString, RE::BSFixedString, bool) { nullptr };
				bool				(*JFormDB_solveObjSetter)(void*, RE::TESForm*, RE::BSFixedString, std::int32_t, bool) { nullptr };
				bool				(*JFormDB_solveFormSetter)(void*, RE::TESForm*, RE::BSFixedString, RE::TESForm*, bool) { nullptr };
				bool				(*JFormDB_hasPath)(void*, RE::TESForm*, RE::BSFixedString) { nullptr };
				std::int32_t		(*JFormDB_allKeys)(void*, RE::TESForm*, RE::BSFixedString) { nullptr };
				std::int32_t		(*JFormDB_allValues)(void*, RE::TESForm*, RE::BSFixedString) { nullptr };
				std::int32_t		(*JFormDB_getInt)(void*, RE::TESForm*, RE::BSFixedString) { nullptr };
				float				(*JFormDB_getFlt)(void*, RE::TESForm*, RE::BSFixedString) { nullptr };
				RE::BSFixedString	(*JFormDB_getStr)(void*, RE::TESForm*, RE::BSFixedString) { nullptr };
				std::int32_t		(*JFormDB_getObj)(void*, RE::TESForm*, RE::BSFixedString) { nullptr };
				RE::TESForm*		(*JFormDB_getForm)(void*, RE::TESForm*, RE::BSFixedString) { nullptr };
				void				(*JFormDB_setInt)(void*, RE::TESForm*, RE::BSFixedString, std::int32_t) { nullptr };
				void				(*JFormDB_setFlt)(void*, RE::TESForm*, RE::BSFixedString, float) { nullptr };
				void				(*JFormDB_setStr)(void*, RE::TESForm*, RE::BSFixedString, RE::BSFixedString) { nullptr };
				void				(*JFormDB_setObj)(void*, RE::TESForm*, RE::BSFixedString, std::int32_t) { nullptr };
				void				(*JFormDB_setForm)(void*, RE::TESForm*, RE::BSFixedString, RE::TESForm*) { nullptr };

				std::int32_t		(*JValue_retain)(void*, std::int32_t, RE::BSFixedString) { nullptr };
				std::int32_t		(*JValue_release)(void*, std::int32_t) { nullptr };
				std::int32_t		(*JValue_releaseAndRetain)(void*, std::int32_t, std::int32_t, RE::BSFixedString) { nullptr };
				void				(*JValue_releaseObjectsWithTag)(void*, RE::BSFixedString) { nullptr };
				std::int32_t		(*JValue_zeroLifetime)(void*, std::int32_t) { nullptr };
				std::int32_t		(*JValue_addToPool)(void*, std::int32_t, RE::BSFixedString) { nullptr };
				void				(*JValue_cleanPool)(void*, RE::BSFixedString) { nullptr };
				std::int32_t		(*JValue_shallowCopy)(void*, std::int32_t) { nullptr };
				std::int32_t		(*JValue_deepCopy)(void*, std::int32_t) { nullptr };
				bool				(*JValue_isExists)(void*, std::int32_t) { nullptr };
				bool				(*JValue_isArray)(void*, std::int32_t) { nullptr };
				bool				(*JValue_isMap)(void*, std::int32_t) { nullptr };
				bool				(*JValue_isFormMap)(void*, std::int32_t) { nullptr };
				bool				(*JValue_isIntegerMap)(void*, std::int32_t) { nullptr };
				bool				(*JValue_empty)(void*, std::int32_t) { nullptr };
				std::int32_t		(*JValue_count)(void*, std::int32_t) { nullptr };
				void				(*JValue_clear)(void*, std::int32_t) { nullptr };
				std::int32_t		(*JValue_readFromFile)(void*, RE::BSFixedString) { nullptr };
				std::int32_t		(*JValue_readFromDirectory)(void*, RE::BSFixedString, RE::BSFixedString) { nullptr };
				std::int32_t		(*JValue_objectFromPrototype)(void*, RE::BSFixedString) { nullptr };
				void				(*JValue_writeToFile)(void*, std::int32_t, RE::BSFixedString) { nullptr };
				bool				(*JValue_hasPath)(void*, std::int32_t, RE::BSFixedString) { nullptr };
				std::int32_t		(*JValue_solvedValueType)(void*, std::int32_t, RE::BSFixedString) { nullptr };
				float				(*JValue_solveFlt)(void*, std::int32_t, RE::BSFixedString, float) { nullptr };
				std::int32_t		(*JValue_solveInt)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
				RE::BSFixedString	(*JValue_solveStr)(void*, std::int32_t, RE::BSFixedString, RE::BSFixedString) { nullptr };
				std::int32_t		(*JValue_solveObj)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
				RE::TESForm*		(*JValue_solveForm)(void*, std::int32_t, RE::BSFixedString, RE::TESForm*) { nullptr };
				bool				(*JValue_solveFltSetter)(void*, std::int32_t, RE::BSFixedString, float, bool) { nullptr };
				bool				(*JValue_solveIntSetter)(void*, std::int32_t, RE::BSFixedString, std::int32_t, bool) { nullptr };
				bool				(*JValue_solveStrSetter)(void*, std::int32_t, RE::BSFixedString, RE::BSFixedString, bool) { nullptr };
				bool				(*JValue_solveObjSetter)(void*, std::int32_t, RE::BSFixedString, std::int32_t, bool) { nullptr };
				bool				(*JValue_solveFormSetter)(void*, std::int32_t, RE::BSFixedString, RE::TESForm*, bool) { nullptr };
				float				(*JValue_evalLuaFlt)(void*, std::int32_t, RE::BSFixedString, float) { nullptr };
				std::int32_t		(*JValue_evalLuaInt)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
				RE::BSFixedString	(*JValue_evalLuaStr)(void*, std::int32_t, RE::BSFixedString, RE::BSFixedString) { nullptr };
				std::int32_t		(*JValue_evalLuaObj)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
				RE::TESForm*		(*JValue_evalLuaForm)(void*, std::int32_t, RE::BSFixedString, RE::TESForm*) { nullptr };

				std::int32_t		(*JArray_object)(void*) { nullptr };
				std::int32_t		(*JArray_objectWithSize)(void*, std::int32_t) { nullptr };
				std::int32_t		(*JArray_objectWithInts)(void*, RE::BSTSmartPointer<RE::BSScript::Array>) { nullptr };
				std::int32_t		(*JArray_objectWithStrings)(void*, RE::BSTSmartPointer<RE::BSScript::Array>) { nullptr };
				std::int32_t		(*JArray_objectWithFloats)(void*, RE::BSTSmartPointer<RE::BSScript::Array>) { nullptr };
				std::int32_t		(*JArray_objectWithBooleans)(void*, RE::BSTSmartPointer<RE::BSScript::Array>) { nullptr };
				std::int32_t		(*JArray_objectWithForms)(void*, RE::BSTSmartPointer<RE::BSScript::Array>) { nullptr };
				std::int32_t		(*JArray_subArray)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				void				(*JArray_addFromArray)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				void				(*JArray_addFromFormList)(void*, std::int32_t, RE::BGSListForm*, std::int32_t) { nullptr };
				std::int32_t		(*JArray_getInt)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				float				(*JArray_getFlt)(void*, std::int32_t, std::int32_t, float) { nullptr };
				RE::BSFixedString	(*JArray_getStr)(void*, std::int32_t, std::int32_t, RE::BSFixedString) { nullptr };
				std::int32_t		(*JArray_getObj)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				RE::TESForm*		(*JArray_getForm)(void*, std::int32_t, std::int32_t, RE::TESForm*) { nullptr };
				std::int32_t		(*JArray_findInt)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				std::int32_t		(*JArray_findFlt)(void*, std::int32_t, float, std::int32_t) { nullptr };
				std::int32_t		(*JArray_findStr)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
				std::int32_t		(*JArray_findObj)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				std::int32_t		(*JArray_findForm)(void*, std::int32_t, RE::TESForm*, std::int32_t) { nullptr };
				void				(*JArray_setInt)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				void				(*JArray_setFlt)(void*, std::int32_t, std::int32_t, float) { nullptr };
				void				(*JArray_setStr)(void*, std::int32_t, std::int32_t, RE::BSFixedString) { nullptr };
				void				(*JArray_setObj)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				void				(*JArray_setForm)(void*, std::int32_t, std::int32_t, RE::TESForm*) { nullptr };
				void				(*JArray_addInt)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				void				(*JArray_addFlt)(void*, std::int32_t, float, std::int32_t) { nullptr };
				void				(*JArray_addStr)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
				void				(*JArray_addObj)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				void				(*JArray_addForm)(void*, std::int32_t, RE::TESForm*, std::int32_t) { nullptr };
				std::int32_t		(*JArray_count)(void*, std::int32_t) { nullptr };
				void				(*JArray_clear)(void*, std::int32_t) { nullptr };
				void				(*JArray_eraseIndex)(void*, std::int32_t, std::int32_t) { nullptr };
				void				(*JArray_eraseRange)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				std::int32_t		(*JArray_valueType)(void*, std::int32_t, std::int32_t) { nullptr };
				void				(*JArray_swapItems)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				std::int32_t		(*JArray_sort)(void*, std::int32_t) { nullptr };
				std::int32_t		(*JArray_unique)(void*, std::int32_t) { nullptr };
				bool				(*JArray_writeToIntegerPArray)(void*, std::int32_t, RE::BSTSmartPointer<RE::BSScript::Array>, std::int32_t, std::int32_t, std::int32_t, std::int32_t) { nullptr };
				bool				(*JArray_writeToFloatPArray)(void*, std::int32_t, RE::BSTSmartPointer<RE::BSScript::Array>, std::int32_t, std::int32_t, std::int32_t, float) { nullptr };
				bool				(*JArray_writeToFormPArray)(void*, std::int32_t, RE::BSTSmartPointer<RE::BSScript::Array>, std::int32_t, std::int32_t, std::int32_t, RE::TESForm*) { nullptr };
				bool				(*JArray_writeToStringPArray)(void*, std::int32_t, RE::BSTSmartPointer<RE::BSScript::Array>, std::int32_t, std::int32_t, std::int32_t, RE::BSFixedString) { nullptr };

				std::int32_t		(*JMap_object)(void*) { nullptr };
				std::int32_t		(*JMap_getInt)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
				float				(*JMap_getFlt)(void*, std::int32_t, RE::BSFixedString, float) { nullptr };
				RE::BSFixedString	(*JMap_getStr)(void*, std::int32_t, RE::BSFixedString, RE::BSFixedString) { nullptr };
				std::int32_t		(*JMap_getObj)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
				RE::TESForm*		(*JMap_getForm)(void*, std::int32_t, RE::BSFixedString, RE::TESForm*) { nullptr };
				void				(*JMap_setInt)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
				void				(*JMap_setFlt)(void*, std::int32_t, RE::BSFixedString, float) { nullptr };
				void				(*JMap_setStr)(void*, std::int32_t, RE::BSFixedString, RE::BSFixedString) { nullptr };
				void				(*JMap_setObj)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
				void				(*JMap_setForm)(void*, std::int32_t, RE::BSFixedString, RE::TESForm*) { nullptr };
				bool				(*JMap_hasKey)(void*, std::int32_t, RE::BSFixedString) { nullptr };
				std::int32_t		(*JMap_valueType)(void*, std::int32_t, RE::BSFixedString) { nullptr };
				std::int32_t		(*JMap_allKeys)(void*, std::int32_t) { nullptr };
				std::vector<RE::BSFixedString>	(*JMap_allKeysPArray)(void*, std::int32_t) { nullptr };
				std::int32_t		(*JMap_allValues)(void*, std::int32_t) { nullptr };
				bool				(*JMap_removeKey)(void*, std::int32_t, RE::BSFixedString) { nullptr };
				std::int32_t		(*JMap_count)(void*, std::int32_t) { nullptr };
				void				(*JMap_clear)(void*, std::int32_t) { nullptr };
				void				(*JMap_addPairs)(void*, std::int32_t, std::int32_t, bool) { nullptr };
				RE::BSFixedString	(*JMap_nextKey)(void*, std::int32_t, RE::BSFixedString, RE::BSFixedString) { nullptr };
				RE::BSFixedString	(*JMap_getNthKey)(void*, std::int32_t, std::int32_t) { nullptr };
			};
		}

		template<class F>
		void obtainFunc(const char* a_funcName, const char* a_className, F& a_func)
		{
			a_func = reinterpret_cast<F>(detail::Storage::get().reflectionInterface->tes_function_of_class(a_funcName, a_className));

			if (!a_func) {
				spdlog::error(FMT_STRING("JContainers: couldn't obtain function {}::{}"), a_className, a_funcName);
			}
		}

		bool initApi(const jc::root_interface* a_root)
		{
			if (!a_root) {
				spdlog::critical("JContainers: couldn't get root interface");
				return false;
			}

			auto& storage = detail::Storage::get();

			storage.reflectionInterface = a_root->query_interface<jc::reflection_interface>();

			if (!storage.reflectionInterface) {
				spdlog::critical("JContainers: couldn't get reflection interface");
				return false;
			}

			storage.domainInterface = a_root->query_interface<jc::domain_interface>();

			if (!storage.domainInterface) {
				spdlog::critical("JContainers: couldn't get domain interface");
				return false;
			}

			obtainFunc("solveFlt", "JDB", storage.JDB_solveFlt);
			obtainFunc("solveInt", "JDB", storage.JDB_solveInt);
			obtainFunc("solveStr", "JDB", storage.JDB_solveStr);
			obtainFunc("solveObj", "JDB", storage.JDB_solveObj);
			obtainFunc("solveForm", "JDB", storage.JDB_solveForm);
			obtainFunc("solveFltSetter", "JDB", storage.JDB_solveFltSetter);
			obtainFunc("solveIntSetter", "JDB", storage.JDB_solveIntSetter);
			obtainFunc("solveStrSetter", "JDB", storage.JDB_solveStrSetter);
			obtainFunc("solveObjSetter", "JDB", storage.JDB_solveObjSetter);
			obtainFunc("solveFormSetter", "JDB", storage.JDB_solveFormSetter);
			obtainFunc("setObj", "JDB", storage.JDB_setObj);
			obtainFunc("hasPath", "JDB", storage.JDB_hasPath);
			obtainFunc("allKeys", "JDB", storage.JDB_allKeys);
			obtainFunc("allValues", "JDB", storage.JDB_allValues);
			obtainFunc("writeToFile", "JDB", storage.JDB_writeToFile);
			//obtainFunc("readFromFile", "JDB", storage.JDB_readFromFile);
			obtainFunc("root", "JDB", storage.JDB_root);

			obtainFunc("setEntry", "JFormDB", storage.JFormDB_setEntry);
			obtainFunc("makeEntry", "JFormDB", storage.JFormDB_makeEntry);
			obtainFunc("findEntry", "JFormDB", storage.JFormDB_findEntry);
			obtainFunc("solveFlt", "JFormDB", storage.JFormDB_solveFlt);
			obtainFunc("solveInt", "JFormDB", storage.JFormDB_solveInt);
			obtainFunc("solveStr", "JFormDB", storage.JFormDB_solveStr);
			obtainFunc("solveObj", "JFormDB", storage.JFormDB_solveObj);
			obtainFunc("solveForm", "JFormDB", storage.JFormDB_solveForm);
			obtainFunc("solveFltSetter", "JFormDB", storage.JFormDB_solveFltSetter);
			obtainFunc("solveIntSetter", "JFormDB", storage.JFormDB_solveIntSetter);
			obtainFunc("solveStrSetter", "JFormDB", storage.JFormDB_solveStrSetter);
			obtainFunc("solveObjSetter", "JFormDB", storage.JFormDB_solveObjSetter);
			obtainFunc("solveFormSetter", "JFormDB", storage.JFormDB_solveFormSetter);
			obtainFunc("hasPath", "JFormDB", storage.JFormDB_hasPath);
			obtainFunc("allKeys", "JFormDB", storage.JFormDB_allKeys);
			obtainFunc("allValues", "JFormDB", storage.JFormDB_allValues);
			obtainFunc("getInt", "JFormDB", storage.JFormDB_getInt);
			obtainFunc("getFlt", "JFormDB", storage.JFormDB_getFlt);
			obtainFunc("getStr", "JFormDB", storage.JFormDB_getStr);
			obtainFunc("getObj", "JFormDB", storage.JFormDB_getObj);
			obtainFunc("getForm", "JFormDB", storage.JFormDB_getForm);
			obtainFunc("setInt", "JFormDB", storage.JFormDB_setInt);
			obtainFunc("setFlt", "JFormDB", storage.JFormDB_setFlt);
			obtainFunc("setStr", "JFormDB", storage.JFormDB_setStr);
			obtainFunc("setObj", "JFormDB", storage.JFormDB_setObj);
			obtainFunc("setForm", "JFormDB", storage.JFormDB_setForm);

			obtainFunc("retain", "JValue", storage.JValue_retain);
			obtainFunc("release", "JValue", storage.JValue_release);
			obtainFunc("releaseAndRetain", "JValue", storage.JValue_releaseAndRetain);
			obtainFunc("releaseObjectsWithTag", "JValue", storage.JValue_releaseObjectsWithTag);
			obtainFunc("zeroLifetime", "JValue", storage.JValue_zeroLifetime);
			obtainFunc("addToPool", "JValue", storage.JValue_addToPool);
			obtainFunc("cleanPool", "JValue", storage.JValue_cleanPool);
			obtainFunc("shallowCopy", "JValue", storage.JValue_shallowCopy);
			obtainFunc("deepCopy", "JValue", storage.JValue_deepCopy);
			obtainFunc("isExists", "JValue", storage.JValue_isExists);
			obtainFunc("isArray", "JValue", storage.JValue_isArray);
			obtainFunc("isMap", "JValue", storage.JValue_isMap);
			obtainFunc("isFormMap", "JValue", storage.JValue_isFormMap);
			obtainFunc("isIntegerMap", "JValue", storage.JValue_isIntegerMap);
			obtainFunc("empty", "JValue", storage.JValue_empty);
			obtainFunc("count", "JValue", storage.JValue_count);
			obtainFunc("clear", "JValue", storage.JValue_clear);
			obtainFunc("readFromFile", "JValue", storage.JValue_readFromFile);
			obtainFunc("readFromDirectory", "JValue", storage.JValue_readFromDirectory);
			obtainFunc("objectFromPrototype", "JValue", storage.JValue_objectFromPrototype);
			obtainFunc("writeToFile", "JValue", storage.JValue_writeToFile);
			obtainFunc("hasPath", "JValue", storage.JValue_hasPath);
			obtainFunc("solvedValueType", "JValue", storage.JValue_solvedValueType);
			obtainFunc("solveFlt", "JValue", storage.JValue_solveFlt);
			obtainFunc("solveInt", "JValue", storage.JValue_solveInt);
			obtainFunc("solveStr", "JValue", storage.JValue_solveStr);
			obtainFunc("solveObj", "JValue", storage.JValue_solveObj);
			obtainFunc("solveForm", "JValue", storage.JValue_solveForm);
			obtainFunc("solveFltSetter", "JValue", storage.JValue_solveFltSetter);
			obtainFunc("solveIntSetter", "JValue", storage.JValue_solveIntSetter);
			obtainFunc("solveStrSetter", "JValue", storage.JValue_solveStrSetter);
			obtainFunc("solveObjSetter", "JValue", storage.JValue_solveObjSetter);
			obtainFunc("solveFormSetter", "JValue", storage.JValue_solveFormSetter);
			obtainFunc("evalLuaFlt", "JValue", storage.JValue_evalLuaFlt);
			obtainFunc("evalLuaInt", "JValue", storage.JValue_evalLuaInt);
			obtainFunc("evalLuaStr", "JValue", storage.JValue_evalLuaStr);
			obtainFunc("evalLuaObj", "JValue", storage.JValue_evalLuaObj);
			obtainFunc("evalLuaForm", "JValue", storage.JValue_evalLuaForm);

			obtainFunc("object", "JArray", storage.JArray_object);
			obtainFunc("objectWithSize", "JArray", storage.JArray_objectWithSize);
			obtainFunc("objectWithInts", "JArray", storage.JArray_objectWithInts);
			obtainFunc("objectWithStrings", "JArray", storage.JArray_objectWithStrings);
			obtainFunc("objectWithFloats", "JArray", storage.JArray_objectWithFloats);
			obtainFunc("objectWithBooleans", "JArray", storage.JArray_objectWithBooleans);
			obtainFunc("objectWithForms", "JArray", storage.JArray_objectWithForms);
			obtainFunc("subArray", "JArray", storage.JArray_subArray);
			obtainFunc("addFromArray", "JArray", storage.JArray_addFromArray);
			obtainFunc("addFromFormList", "JArray", storage.JArray_addFromFormList);
			obtainFunc("getInt", "JArray", storage.JArray_getInt);
			obtainFunc("getFlt", "JArray", storage.JArray_getFlt);
			obtainFunc("getStr", "JArray", storage.JArray_getStr);
			obtainFunc("getObj", "JArray", storage.JArray_getObj);
			obtainFunc("getForm", "JArray", storage.JArray_getForm);
			obtainFunc("findInt", "JArray", storage.JArray_findInt);
			obtainFunc("findFlt", "JArray", storage.JArray_findFlt);
			obtainFunc("findStr", "JArray", storage.JArray_findStr);
			obtainFunc("findObj", "JArray", storage.JArray_findObj);
			obtainFunc("findForm", "JArray", storage.JArray_findForm);
			obtainFunc("setInt", "JArray", storage.JArray_setInt);
			obtainFunc("setFlt", "JArray", storage.JArray_setFlt);
			obtainFunc("setStr", "JArray", storage.JArray_setStr);
			obtainFunc("setObj", "JArray", storage.JArray_setObj);
			obtainFunc("setForm", "JArray", storage.JArray_setForm);
			obtainFunc("addInt", "JArray", storage.JArray_addInt);
			obtainFunc("addFlt", "JArray", storage.JArray_addFlt);
			obtainFunc("addStr", "JArray", storage.JArray_addStr);
			obtainFunc("addObj", "JArray", storage.JArray_addObj);
			obtainFunc("addForm", "JArray", storage.JArray_addForm);
			obtainFunc("count", "JArray", storage.JArray_count);
			obtainFunc("clear", "JArray", storage.JArray_clear);
			obtainFunc("eraseIndex", "JArray", storage.JArray_eraseIndex);
			obtainFunc("eraseRange", "JArray", storage.JArray_eraseRange);
			obtainFunc("valueType", "JArray", storage.JArray_valueType);
			obtainFunc("swapItems", "JArray", storage.JArray_swapItems);
			obtainFunc("sort", "JArray", storage.JArray_sort);
			obtainFunc("unique", "JArray", storage.JArray_unique);
			obtainFunc("writeToIntegerPArray", "JArray", storage.JArray_writeToIntegerPArray);
			obtainFunc("writeToFloatPArray", "JArray", storage.JArray_writeToFloatPArray);
			obtainFunc("writeToFormPArray", "JArray", storage.JArray_writeToFormPArray);
			obtainFunc("writeToStringPArray", "JArray", storage.JArray_writeToStringPArray);

			obtainFunc("object", "JMap", storage.JMap_object);
			obtainFunc("getInt", "JMap", storage.JMap_getInt);
			obtainFunc("getFlt", "JMap", storage.JMap_getFlt);
			obtainFunc("getStr", "JMap", storage.JMap_getStr);
			obtainFunc("getObj", "JMap", storage.JMap_getObj);
			obtainFunc("getForm", "JMap", storage.JMap_getForm);
			obtainFunc("setInt", "JMap", storage.JMap_setInt);
			obtainFunc("setFlt", "JMap", storage.JMap_setFlt);
			obtainFunc("setStr", "JMap", storage.JMap_setStr);
			obtainFunc("setObj", "JMap", storage.JMap_setObj);
			obtainFunc("setForm", "JMap", storage.JMap_setForm);
			obtainFunc("hasKey", "JMap", storage.JMap_hasKey);
			obtainFunc("valueType", "JMap", storage.JMap_valueType);
			obtainFunc("allKeys", "JMap", storage.JMap_allKeys);
			obtainFunc("allKeysPArray", "JMap", storage.JMap_allKeysPArray);
			obtainFunc("allValues", "JMap", storage.JMap_allValues);
			obtainFunc("removeKey", "JMap", storage.JMap_removeKey);
			obtainFunc("count", "JMap", storage.JMap_count);
			obtainFunc("clear", "JMap", storage.JMap_clear);
			obtainFunc("addPairs", "JMap", storage.JMap_addPairs);
			obtainFunc("nextKey", "JMap", storage.JMap_nextKey);
			obtainFunc("getNthKey", "JMap", storage.JMap_getNthKey);

			return true;
		}

		void onApiAvailable(const jc::root_interface* a_root)
		{
			spdlog::info("JContainers: api initialization...");

			bool result = initApi(a_root);

			if (result) {
				spdlog::info("JContainers: api initialized");
			} else {
				spdlog::error("JContainers: api initialization failed");
			}

			if (detail::Storage::get().onInitComplete) {
				detail::Storage::get().onInitComplete(result);
			}
		}

		void onPostLoad()
		{
			auto result = SKSE::GetMessagingInterface()->RegisterListener(JC_PLUGIN_NAME, [](SKSE::MessagingInterface::Message* a_msg) {
				if (a_msg && a_msg->type == jc::message_root_interface) {
					onApiAvailable(jc::root_interface::from_void(a_msg->data));
				}
			});

			if (!result) {
				spdlog::error("JContainers: api initialization failed");
			}

			if (!result && detail::Storage::get().onInitComplete) {
				detail::Storage::get().onInitComplete(false);
			}
		}

		void init(std::function<void(bool)> a_onInitComplete)
		{
			detail::Storage::get().onInitComplete = a_onInitComplete;

			SKSE::GetMessagingInterface()->RegisterListener("SKSE", [](SKSE::MessagingInterface::Message* a_msg) {
				if (a_msg && a_msg->type == SKSE::MessagingInterface::kPostLoad) {
					onPostLoad();
				}
			});
		}

		bool setDefaultDomain(const char* a_name)
		{
			auto domain = domain::get(a_name);

			if (!domain) {
				return false;
			}

			detail::Storage::get().defaultDomain = domain;
			return true;
		}
	}

	using ApiStorage = api::detail::Storage;

	namespace domain
	{
		void* get(const char* a_name)
		{
			auto domain = a_name && *a_name ? ApiStorage::get().domainInterface->get_domain_with_name(a_name) : ApiStorage::get().domainInterface->get_default_domain();
			
			if (!domain) {
				spdlog::error("JContainers: couldn't get domain '{}'", a_name && *a_name ? a_name : "");
			}

			return domain;
		}
	}

	namespace JDB
	{
		float solveFlt(RE::BSFixedString a_path, float a_default)
		{
			return ApiStorage::get().JDB_solveFlt(ApiStorage::get().defaultDomain, a_path, a_default);
		}

		std::int32_t solveInt(RE::BSFixedString a_path, std::int32_t a_default)
		{
			return ApiStorage::get().JDB_solveInt(ApiStorage::get().defaultDomain, a_path, a_default);
		}

		RE::BSFixedString solveStr(RE::BSFixedString a_path, RE::BSFixedString a_default)
		{
			return ApiStorage::get().JDB_solveStr(ApiStorage::get().defaultDomain, a_path, a_default);
		}

		std::int32_t solveObj(RE::BSFixedString a_path, std::int32_t a_default)
		{
			return ApiStorage::get().JDB_solveObj(ApiStorage::get().defaultDomain, a_path, a_default);
		}

		RE::TESForm* solveForm(RE::BSFixedString a_path, RE::TESForm* a_default)
		{
			return ApiStorage::get().JDB_solveForm(ApiStorage::get().defaultDomain, a_path, a_default);
		}

		bool solveFltSetter(RE::BSFixedString a_path, float a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JDB_solveFltSetter(ApiStorage::get().defaultDomain, a_path, a_value, a_createMissingKeys);
		}

		bool solveIntSetter(RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JDB_solveIntSetter(ApiStorage::get().defaultDomain, a_path, a_value, a_createMissingKeys);
		}

		bool solveStrSetter(RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JDB_solveStrSetter(ApiStorage::get().defaultDomain, a_path, a_value, a_createMissingKeys);
		}

		bool solveObjSetter(RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JDB_solveObjSetter(ApiStorage::get().defaultDomain, a_path, a_value, a_createMissingKeys);
		}
		bool solveFormSetter(RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JDB_solveFormSetter(ApiStorage::get().defaultDomain, a_path, a_value, a_createMissingKeys);
		}

		void setObj(RE::BSFixedString a_key, std::int32_t a_obj)
		{
			ApiStorage::get().JDB_setObj(ApiStorage::get().defaultDomain, a_key, a_obj);
		}

		bool hasPath(RE::BSFixedString a_path)
		{
			return ApiStorage::get().JDB_hasPath(ApiStorage::get().defaultDomain, a_path);
		}

		std::int32_t allKeys()
		{
			return ApiStorage::get().JDB_allKeys(ApiStorage::get().defaultDomain);
		}

		std::int32_t allValues()
		{
			return ApiStorage::get().JDB_allValues(ApiStorage::get().defaultDomain);
		}

		void writeToFile(RE::BSFixedString a_path)
		{
			ApiStorage::get().JDB_writeToFile(ApiStorage::get().defaultDomain, a_path);
		}

		void readFromFile(RE::BSFixedString a_path)
		{
			ApiStorage::get().JDB_readFromFile(ApiStorage::get().defaultDomain, a_path);
		}

		std::int32_t root()
		{
			return ApiStorage::get().JDB_root(ApiStorage::get().defaultDomain);
		}
	}

	namespace JFormDB
	{
		void setEntry(RE::BSFixedString a_storageName, RE::TESForm* a_fKey, std::int32_t a_entry)
		{
			ApiStorage::get().JFormDB_setEntry(ApiStorage::get().defaultDomain, a_storageName, a_fKey, a_entry);
		}

		std::int32_t makeEntry(RE::BSFixedString a_storageName, RE::TESForm* a_fKey)
		{
			return ApiStorage::get().JFormDB_makeEntry(ApiStorage::get().defaultDomain, a_storageName, a_fKey);
		}

		std::int32_t findEntry(RE::BSFixedString a_storageName, RE::TESForm* a_fKey)
		{
			return ApiStorage::get().JFormDB_findEntry(ApiStorage::get().defaultDomain, a_storageName, a_fKey);
		}

		float solveFlt(RE::TESForm* a_fKey, RE::BSFixedString a_path, float a_default)
		{
			return ApiStorage::get().JFormDB_solveFlt(ApiStorage::get().defaultDomain, a_fKey, a_path, a_default);
		}

		std::int32_t solveInt(RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_default)
		{
			return ApiStorage::get().JFormDB_solveInt(ApiStorage::get().defaultDomain, a_fKey, a_path, a_default);
		}

		RE::BSFixedString solveStr(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::BSFixedString a_default)
		{
			return ApiStorage::get().JFormDB_solveStr(ApiStorage::get().defaultDomain, a_fKey, a_path, a_default);
		}

		std::int32_t solveObj(RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_default)
		{
			return ApiStorage::get().JFormDB_solveObj(ApiStorage::get().defaultDomain, a_fKey, a_path, a_default);
		}

		RE::TESForm* solveForm(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::TESForm* a_default)
		{
			return ApiStorage::get().JFormDB_solveForm(ApiStorage::get().defaultDomain, a_fKey, a_path, a_default);
		}

		bool solveFltSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JFormDB_solveFltSetter(ApiStorage::get().defaultDomain, a_fKey, a_path, a_value, a_createMissingKeys);
		}

		bool solveIntSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JFormDB_solveIntSetter(ApiStorage::get().defaultDomain, a_fKey, a_path, a_value, a_createMissingKeys);
		}

		bool solveStrSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JFormDB_solveStrSetter(ApiStorage::get().defaultDomain, a_fKey, a_path, a_value, a_createMissingKeys);
		}

		bool solveObjSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JFormDB_solveObjSetter(ApiStorage::get().defaultDomain, a_fKey, a_path, a_value, a_createMissingKeys);
		}

		bool solveFormSetter(RE::TESForm* a_fKey, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JFormDB_solveFormSetter(ApiStorage::get().defaultDomain, a_fKey, a_path, a_value, a_createMissingKeys);
		}

		bool hasPath(RE::TESForm* a_fKey, RE::BSFixedString a_path)
		{
			return ApiStorage::get().JFormDB_hasPath(ApiStorage::get().defaultDomain, a_fKey, a_path);
		}

		std::int32_t allKeys(RE::TESForm* a_fKey, RE::BSFixedString a_key)
		{
			return ApiStorage::get().JFormDB_allKeys(ApiStorage::get().defaultDomain, a_fKey, a_key);
		}

		std::int32_t allValues(RE::TESForm* a_fKey, RE::BSFixedString a_key)
		{
			return ApiStorage::get().JFormDB_allValues(ApiStorage::get().defaultDomain, a_fKey, a_key);
		}

		std::int32_t getInt(RE::TESForm* a_fKey, RE::BSFixedString a_key)
		{
			return ApiStorage::get().JFormDB_getInt(ApiStorage::get().defaultDomain, a_fKey, a_key);
		}

		float getFlt(RE::TESForm* a_fKey, RE::BSFixedString a_key)
		{
			return ApiStorage::get().JFormDB_getFlt(ApiStorage::get().defaultDomain, a_fKey, a_key);
		}

		RE::BSFixedString getStr(RE::TESForm* a_fKey, RE::BSFixedString a_key)
		{
			return ApiStorage::get().JFormDB_getStr(ApiStorage::get().defaultDomain, a_fKey, a_key);
		}

		std::int32_t getObj(RE::TESForm* a_fKey, RE::BSFixedString a_key)
		{
			return ApiStorage::get().JFormDB_getObj(ApiStorage::get().defaultDomain, a_fKey, a_key);
		}

		RE::TESForm* getForm(RE::TESForm* a_fKey, RE::BSFixedString a_key)
		{
			return ApiStorage::get().JFormDB_getForm(ApiStorage::get().defaultDomain, a_fKey, a_key);
		}

		void setInt(RE::TESForm* a_fKey, RE::BSFixedString a_key, std::int32_t a_value)
		{
			ApiStorage::get().JFormDB_setInt(ApiStorage::get().defaultDomain, a_fKey, a_key, a_value);
		}

		void setFlt(RE::TESForm* a_fKey, RE::BSFixedString a_key, float a_value)
		{
			ApiStorage::get().JFormDB_setFlt(ApiStorage::get().defaultDomain, a_fKey, a_key, a_value);
		}

		void setStr(RE::TESForm* a_fKey, RE::BSFixedString a_key, RE::BSFixedString a_value)
		{
			ApiStorage::get().JFormDB_setStr(ApiStorage::get().defaultDomain, a_fKey, a_key, a_value);
		}

		void setObj(RE::TESForm* a_fKey, RE::BSFixedString a_key, std::int32_t a_container)
		{
			ApiStorage::get().JFormDB_setObj(ApiStorage::get().defaultDomain, a_fKey, a_key, a_container);
		}

		void setForm(RE::TESForm* a_fKey, RE::BSFixedString a_key, RE::TESForm* a_value)
		{
			ApiStorage::get().JFormDB_setForm(ApiStorage::get().defaultDomain, a_fKey, a_key, a_value);
		}
	}

	namespace JValue
	{
		std::int32_t retain(std::int32_t a_obj, RE::BSFixedString a_tag)
		{
			return ApiStorage::get().JValue_retain(ApiStorage::get().defaultDomain, a_obj, a_tag);
		}

		std::int32_t release(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_release(ApiStorage::get().defaultDomain, a_obj);
		}

		std::int32_t releaseAndRetain(std::int32_t a_previousObject, std::int32_t a_newObject, RE::BSFixedString a_tag)
		{
			return ApiStorage::get().JValue_releaseAndRetain(ApiStorage::get().defaultDomain, a_previousObject, a_newObject, a_tag);
		}

		void releaseObjectsWithTag(RE::BSFixedString a_tag)
		{
			ApiStorage::get().JValue_releaseObjectsWithTag(ApiStorage::get().defaultDomain, a_tag);
		}

		std::int32_t zeroLifetime(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_zeroLifetime(ApiStorage::get().defaultDomain, a_obj);
		}

		std::int32_t addToPool(std::int32_t a_obj, RE::BSFixedString a_poolName)
		{
			return ApiStorage::get().JValue_addToPool(ApiStorage::get().defaultDomain, a_obj, a_poolName);
		}

		void cleanPool(RE::BSFixedString a_poolName)
		{
			ApiStorage::get().JValue_cleanPool(ApiStorage::get().defaultDomain, a_poolName);
		}

		std::int32_t shallowCopy(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_shallowCopy(ApiStorage::get().defaultDomain, a_obj);
		}

		std::int32_t deepCopy(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_deepCopy(ApiStorage::get().defaultDomain, a_obj);
		}

		bool isExists(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_isExists(ApiStorage::get().defaultDomain, a_obj);
		}

		bool isArray(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_isArray(ApiStorage::get().defaultDomain, a_obj);
		}

		bool isMap(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_isMap(ApiStorage::get().defaultDomain, a_obj);
		}

		bool isFormMap(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_isFormMap(ApiStorage::get().defaultDomain, a_obj);
		}

		bool isIntegerMap(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_isIntegerMap(ApiStorage::get().defaultDomain, a_obj);
		}

		bool empty(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_empty(ApiStorage::get().defaultDomain, a_obj);
		}

		std::int32_t count(std::int32_t a_obj)
		{
			return ApiStorage::get().JValue_count(ApiStorage::get().defaultDomain, a_obj);
		}

		void clear(std::int32_t a_obj)
		{
			ApiStorage::get().JValue_clear(ApiStorage::get().defaultDomain, a_obj);
		}

		std::int32_t readFromFile(RE::BSFixedString a_filePath)
		{
			return ApiStorage::get().JValue_readFromFile(ApiStorage::get().defaultDomain, a_filePath);
		}

		std::int32_t readFromDirectory(RE::BSFixedString a_directoryPath, RE::BSFixedString a_extension)
		{
			return ApiStorage::get().JValue_readFromDirectory(ApiStorage::get().defaultDomain, a_directoryPath, a_extension);
		}

		std::int32_t objectFromPrototype(RE::BSFixedString a_prototype)
		{
			return ApiStorage::get().JValue_objectFromPrototype(ApiStorage::get().defaultDomain, a_prototype);
		}

		void writeToFile(std::int32_t a_obj, RE::BSFixedString a_filePath)
		{
			ApiStorage::get().JValue_writeToFile(ApiStorage::get().defaultDomain, a_obj, a_filePath);
		}

		bool hasPath(std::int32_t a_obj, RE::BSFixedString a_path)
		{
			return ApiStorage::get().JValue_hasPath(ApiStorage::get().defaultDomain, a_obj, a_path);
		}

		std::int32_t solvedValueType(std::int32_t a_obj, RE::BSFixedString a_path)
		{
			return ApiStorage::get().JValue_solvedValueType(ApiStorage::get().defaultDomain, a_obj, a_path);
		}

		float solveFlt(std::int32_t a_obj, RE::BSFixedString a_path, float a_default)
		{
			return ApiStorage::get().JValue_solveFlt(ApiStorage::get().defaultDomain, a_obj, a_path, a_default);
		}

		std::int32_t solveInt(std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_default)
		{
			return ApiStorage::get().JValue_solveInt(ApiStorage::get().defaultDomain, a_obj, a_path, a_default);
		}

		RE::BSFixedString solveStr(std::int32_t a_obj, RE::BSFixedString a_path, RE::BSFixedString a_default)
		{
			return ApiStorage::get().JValue_solveStr(ApiStorage::get().defaultDomain, a_obj, a_path, a_default);
		}

		std::int32_t solveObj(std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_default)
		{
			return ApiStorage::get().JValue_solveObj(ApiStorage::get().defaultDomain, a_obj, a_path, a_default);
		}

		RE::TESForm* solveForm(std::int32_t a_obj, RE::BSFixedString a_path, RE::TESForm* a_default)
		{
			return ApiStorage::get().JValue_solveForm(ApiStorage::get().defaultDomain, a_obj, a_path, a_default);
		}

		bool solveFltSetter(std::int32_t a_obj, RE::BSFixedString a_path, float a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JValue_solveFltSetter(ApiStorage::get().defaultDomain, a_obj, a_path, a_value, a_createMissingKeys);
		}

		bool solveIntSetter(std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JValue_solveIntSetter(ApiStorage::get().defaultDomain, a_obj, a_path, a_value, a_createMissingKeys);
		}

		bool solveStrSetter(std::int32_t a_obj, RE::BSFixedString a_path, RE::BSFixedString a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JValue_solveStrSetter(ApiStorage::get().defaultDomain, a_obj, a_path, a_value, a_createMissingKeys);
		}

		bool solveObjSetter(std::int32_t a_obj, RE::BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JValue_solveObjSetter(ApiStorage::get().defaultDomain, a_obj, a_path, a_value, a_createMissingKeys);
		}

		bool solveFormSetter(std::int32_t a_obj, RE::BSFixedString a_path, RE::TESForm* a_value, bool a_createMissingKeys)
		{
			return ApiStorage::get().JValue_solveFormSetter(ApiStorage::get().defaultDomain, a_obj, a_path, a_value, a_createMissingKeys);
		}

		float evalLuaFlt(std::int32_t a_obj, RE::BSFixedString a_luaCode, float a_default)
		{
			return ApiStorage::get().JValue_evalLuaFlt(ApiStorage::get().defaultDomain, a_obj, a_luaCode, a_default);
		}

		std::int32_t evalLuaInt(std::int32_t a_obj, RE::BSFixedString a_luaCode, std::int32_t a_default)
		{
			return ApiStorage::get().JValue_evalLuaInt(ApiStorage::get().defaultDomain, a_obj, a_luaCode, a_default);
		}

		RE::BSFixedString evalLuaStr(std::int32_t a_obj, RE::BSFixedString a_luaCode, RE::BSFixedString a_default)
		{
			return ApiStorage::get().JValue_evalLuaStr(ApiStorage::get().defaultDomain, a_obj, a_luaCode, a_default);
		}

		std::int32_t evalLuaObj(std::int32_t a_obj, RE::BSFixedString a_luaCode, std::int32_t a_default)
		{
			return ApiStorage::get().JValue_evalLuaObj(ApiStorage::get().defaultDomain, a_obj, a_luaCode, a_default);
		}

		RE::TESForm* evalLuaForm(std::int32_t a_obj, RE::BSFixedString a_luaCode, RE::TESForm* a_default)
		{
			return ApiStorage::get().JValue_evalLuaForm(ApiStorage::get().defaultDomain, a_obj, a_luaCode, a_default);
		}
	}

	namespace JArray
	{
		std::int32_t object()
		{
			return ApiStorage::get().JArray_object(ApiStorage::get().defaultDomain);
		}

		std::int32_t objectWithSize(std::int32_t a_size)
		{
			return ApiStorage::get().JArray_objectWithSize(ApiStorage::get().defaultDomain, a_size);
		}

		std::int32_t objectWithInts(RE::BSTSmartPointer<RE::BSScript::Array> a_values)
		{
			return ApiStorage::get().JArray_objectWithInts(ApiStorage::get().defaultDomain, a_values);
		}

		std::int32_t objectWithStrings(RE::BSTSmartPointer<RE::BSScript::Array> a_values)
		{
			return ApiStorage::get().JArray_objectWithStrings(ApiStorage::get().defaultDomain, a_values);
		}

		std::int32_t objectWithFloats(RE::BSTSmartPointer<RE::BSScript::Array> a_values)
		{
			return ApiStorage::get().JArray_objectWithFloats(ApiStorage::get().defaultDomain, a_values);
		}

		std::int32_t objectWithBooleans(RE::BSTSmartPointer<RE::BSScript::Array> a_values)
		{
			return ApiStorage::get().JArray_objectWithBooleans(ApiStorage::get().defaultDomain, a_values);
		}

		std::int32_t objectWithForms(RE::BSTSmartPointer<RE::BSScript::Array> a_values)
		{
			return ApiStorage::get().JArray_objectWithForms(ApiStorage::get().defaultDomain, a_values);
		}

		std::int32_t subArray(std::int32_t a_obj, std::int32_t a_startIndex, std::int32_t a_endIndex)
		{
			return ApiStorage::get().JArray_subArray(ApiStorage::get().defaultDomain, a_obj, a_startIndex, a_endIndex);
		}

		void addFromArray(std::int32_t a_obj, std::int32_t a_source, std::int32_t a_insertAtIndex)
		{
			ApiStorage::get().JArray_addFromArray(ApiStorage::get().defaultDomain, a_obj, a_source, a_insertAtIndex);
		}

		void addFromFormList(std::int32_t a_obj, RE::BGSListForm* a_source, std::int32_t a_insertAtIndex)
		{
			ApiStorage::get().JArray_addFromFormList(ApiStorage::get().defaultDomain, a_obj, a_source, a_insertAtIndex);
		}

		std::int32_t getInt(std::int32_t a_obj, std::int32_t a_index, std::int32_t a_default)
		{
			return ApiStorage::get().JArray_getInt(ApiStorage::get().defaultDomain, a_obj, a_index, a_default);
		}

		float getFlt(std::int32_t a_obj, std::int32_t a_index, float a_default)
		{
			return ApiStorage::get().JArray_getFlt(ApiStorage::get().defaultDomain, a_obj, a_index, a_default);
		}

		RE::BSFixedString getStr(std::int32_t a_obj, std::int32_t a_index, RE::BSFixedString a_default)
		{
			return ApiStorage::get().JArray_getStr(ApiStorage::get().defaultDomain, a_obj, a_index, a_default);
		}

		std::int32_t getObj(std::int32_t a_obj, std::int32_t a_index, std::int32_t a_default)
		{
			return ApiStorage::get().JArray_getObj(ApiStorage::get().defaultDomain, a_obj, a_index, a_default);
		}

		RE::TESForm* getForm(std::int32_t a_obj, std::int32_t a_index, RE::TESForm* a_default)
		{
			return ApiStorage::get().JArray_getForm(ApiStorage::get().defaultDomain, a_obj, a_index, a_default);
		}

		std::int32_t findInt(std::int32_t a_obj, std::int32_t a_value, std::int32_t a_searchStartIndex)
		{
			return ApiStorage::get().JArray_findInt(ApiStorage::get().defaultDomain, a_obj, a_value, a_searchStartIndex);
		}

		std::int32_t findFlt(std::int32_t a_obj, float a_value, std::int32_t a_searchStartIndex)
		{
			return ApiStorage::get().JArray_findFlt(ApiStorage::get().defaultDomain, a_obj, a_value, a_searchStartIndex);
		}

		std::int32_t findStr(std::int32_t a_obj, RE::BSFixedString a_value, std::int32_t a_searchStartIndex)
		{
			return ApiStorage::get().JArray_findStr(ApiStorage::get().defaultDomain, a_obj, a_value, a_searchStartIndex);
		}

		std::int32_t findObj(std::int32_t a_obj, std::int32_t a_value, std::int32_t a_searchStartIndex)
		{
			return ApiStorage::get().JArray_findObj(ApiStorage::get().defaultDomain, a_obj, a_value, a_searchStartIndex);
		}

		std::int32_t findForm(std::int32_t a_obj, RE::TESForm* a_value, std::int32_t a_searchStartIndex)
		{
			return ApiStorage::get().JArray_findForm(ApiStorage::get().defaultDomain, a_obj, a_value, a_searchStartIndex);
		}

		void setInt(std::int32_t a_obj, std::int32_t a_index, std::int32_t a_value)
		{
			ApiStorage::get().JArray_setInt(ApiStorage::get().defaultDomain, a_obj, a_index, a_value);
		}

		void setFlt(std::int32_t a_obj, std::int32_t a_index, float a_value)
		{
			ApiStorage::get().JArray_setFlt(ApiStorage::get().defaultDomain, a_obj, a_index, a_value);
		}

		void setStr(std::int32_t a_obj, std::int32_t a_index, RE::BSFixedString a_value)
		{
			ApiStorage::get().JArray_setStr(ApiStorage::get().defaultDomain, a_obj, a_index, a_value);
		}

		void setObj(std::int32_t a_obj, std::int32_t a_index, std::int32_t a_value)
		{
			ApiStorage::get().JArray_setObj(ApiStorage::get().defaultDomain, a_obj, a_index, a_value);
		}

		void setForm(std::int32_t a_obj, std::int32_t a_index, RE::TESForm* a_value)
		{
			ApiStorage::get().JArray_setForm(ApiStorage::get().defaultDomain, a_obj, a_index, a_value);
		}

		void addInt(std::int32_t a_obj, std::int32_t a_value, std::int32_t a_index)
		{
			ApiStorage::get().JArray_addInt(ApiStorage::get().defaultDomain, a_obj, a_value, a_index);
		}

		void addFlt(std::int32_t a_obj, float a_value, std::int32_t a_index)
		{
			ApiStorage::get().JArray_addFlt(ApiStorage::get().defaultDomain, a_obj, a_value, a_index);
		}

		void addStr(std::int32_t a_obj, RE::BSFixedString a_value, std::int32_t a_index)
		{
			ApiStorage::get().JArray_addStr(ApiStorage::get().defaultDomain, a_obj, a_value, a_index);
		}

		void addObj(std::int32_t a_obj, std::int32_t a_value, std::int32_t a_index)
		{
			ApiStorage::get().JArray_addObj(ApiStorage::get().defaultDomain, a_obj, a_value, a_index);
		}

		void addForm(std::int32_t a_obj, RE::TESForm* a_value, std::int32_t a_index)
		{
			ApiStorage::get().JArray_addForm(ApiStorage::get().defaultDomain, a_obj, a_value, a_index);
		}

		std::int32_t count(std::int32_t a_obj)
		{
			return ApiStorage::get().JArray_count(ApiStorage::get().defaultDomain, a_obj);
		}

		void clear(std::int32_t a_obj)
		{
			ApiStorage::get().JArray_clear(ApiStorage::get().defaultDomain, a_obj);
		}

		void eraseIndex(std::int32_t a_obj, std::int32_t a_index)
		{
			ApiStorage::get().JArray_eraseIndex(ApiStorage::get().defaultDomain, a_obj, a_index);
		}

		void eraseRange(std::int32_t a_obj, std::int32_t a_first, std::int32_t a_last)
		{
			ApiStorage::get().JArray_eraseRange(ApiStorage::get().defaultDomain, a_obj, a_first, a_last);
		}

		std::int32_t valueType(std::int32_t a_obj, std::int32_t a_index)
		{
			return ApiStorage::get().JArray_valueType(ApiStorage::get().defaultDomain, a_obj, a_index);
		}

		void swapItems(std::int32_t a_obj, std::int32_t a_index1, std::int32_t a_index2)
		{
			ApiStorage::get().JArray_swapItems(ApiStorage::get().defaultDomain, a_obj, a_index1, a_index2);
		}

		std::int32_t sort(std::int32_t a_obj)
		{
			return ApiStorage::get().JArray_sort(ApiStorage::get().defaultDomain, a_obj);
		}

		std::int32_t unique(std::int32_t a_obj)
		{
			return ApiStorage::get().JArray_unique(ApiStorage::get().defaultDomain, a_obj);
		}

		bool writeToIntegerPArray(std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx, std::int32_t a_stopWriteAtIdx, std::int32_t a_readIdx, std::int32_t a_defaultRead)
		{
			return ApiStorage::get().JArray_writeToIntegerPArray(ApiStorage::get().defaultDomain, a_obj, a_targetArray, a_stopWriteAtIdx, a_stopWriteAtIdx, a_readIdx, a_defaultRead);
		}

		bool writeToFloatPArray(std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx, std::int32_t a_stopWriteAtIdx, std::int32_t a_readIdx, float a_defaultRead)
		{
			return ApiStorage::get().JArray_writeToFloatPArray(ApiStorage::get().defaultDomain, a_obj, a_targetArray, a_writeAtIdx, a_stopWriteAtIdx, a_readIdx, a_defaultRead);
		}

		bool writeToFormPArray(std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx, std::int32_t a_stopWriteAtIdx, std::int32_t a_readIdx, RE::TESForm* a_defaultRead)
		{
			return ApiStorage::get().JArray_writeToFormPArray(ApiStorage::get().defaultDomain, a_obj, a_targetArray, a_writeAtIdx, a_stopWriteAtIdx, a_readIdx, a_defaultRead);
		}

		bool writeToStringPArray(std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx, std::int32_t a_stopWriteAtIdx, std::int32_t a_readIdx, RE::BSFixedString a_defaultRead)
		{
			return ApiStorage::get().JArray_writeToStringPArray(ApiStorage::get().defaultDomain, a_obj, a_targetArray, a_writeAtIdx, a_stopWriteAtIdx, a_readIdx, a_defaultRead);
		}
	}

	namespace JMap
	{
		std::int32_t object()
		{
			return ApiStorage::get().JMap_object(ApiStorage::get().defaultDomain);
		}

		std::int32_t getInt(std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_default)
		{
			return ApiStorage::get().JMap_getInt(ApiStorage::get().defaultDomain, a_obj, a_key, a_default);
		}

		float getFlt(std::int32_t a_obj, RE::BSFixedString a_key, float a_default)
		{
			return ApiStorage::get().JMap_getFlt(ApiStorage::get().defaultDomain, a_obj, a_key, a_default);
		}

		RE::BSFixedString getStr(std::int32_t a_obj, RE::BSFixedString a_key, RE::BSFixedString a_default)
		{
			return ApiStorage::get().JMap_getStr(ApiStorage::get().defaultDomain, a_obj, a_key, a_default);
		}

		std::int32_t getObj(std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_default)
		{
			return ApiStorage::get().JMap_getObj(ApiStorage::get().defaultDomain, a_obj, a_key, a_default);
		}

		RE::TESForm* getForm(std::int32_t a_obj, RE::BSFixedString a_key, RE::TESForm* a_default)
		{
			return ApiStorage::get().JMap_getForm(ApiStorage::get().defaultDomain, a_obj, a_key, a_default);
		}

		void setInt(std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_value)
		{
			ApiStorage::get().JMap_setInt(ApiStorage::get().defaultDomain, a_obj, a_key, a_value);
		}

		void setFlt(std::int32_t a_obj, RE::BSFixedString a_key, float a_value)
		{
			ApiStorage::get().JMap_setFlt(ApiStorage::get().defaultDomain, a_obj, a_key, a_value);
		}

		void setStr(std::int32_t a_obj, RE::BSFixedString a_key, RE::BSFixedString a_value)
		{
			ApiStorage::get().JMap_setStr(ApiStorage::get().defaultDomain, a_obj, a_key, a_value);
		}

		void setObj(std::int32_t a_obj, RE::BSFixedString a_key, std::int32_t a_container)
		{
			ApiStorage::get().JMap_setObj(ApiStorage::get().defaultDomain, a_obj, a_key, a_container);
		}

		void setForm(std::int32_t a_obj, RE::BSFixedString a_key, RE::TESForm* a_value)
		{
			ApiStorage::get().JMap_setForm(ApiStorage::get().defaultDomain, a_obj, a_key, a_value);
		}

		bool hasKey(std::int32_t a_obj, RE::BSFixedString a_key)
		{
			return ApiStorage::get().JMap_hasKey(ApiStorage::get().defaultDomain, a_obj, a_key);
		}

		std::int32_t valueType(std::int32_t a_obj, RE::BSFixedString a_key)
		{
			return ApiStorage::get().JMap_valueType(ApiStorage::get().defaultDomain, a_obj, a_key);
		}

		std::int32_t allKeys(std::int32_t a_obj)
		{
			return ApiStorage::get().JMap_allKeys(ApiStorage::get().defaultDomain, a_obj);
		}

		std::vector<RE::BSFixedString> allKeysPArray(std::int32_t a_obj)
		{
			return ApiStorage::get().JMap_allKeysPArray(ApiStorage::get().defaultDomain, a_obj);
		}

		std::int32_t allValues(std::int32_t a_obj)
		{
			return ApiStorage::get().JMap_allValues(ApiStorage::get().defaultDomain, a_obj);
		}

		bool removeKey(std::int32_t a_obj, RE::BSFixedString a_key)
		{
			return ApiStorage::get().JMap_removeKey(ApiStorage::get().defaultDomain, a_obj, a_key);
		}

		std::int32_t count(std::int32_t a_obj)
		{
			return ApiStorage::get().JMap_count(ApiStorage::get().defaultDomain, a_obj);
		}

		void clear(std::int32_t a_obj)
		{
			ApiStorage::get().JMap_clear(ApiStorage::get().defaultDomain, a_obj);
		}

		void addPairs(std::int32_t a_obj, std::int32_t a_source, bool a_overrideDuplicates)
		{
			ApiStorage::get().JMap_addPairs(ApiStorage::get().defaultDomain, a_obj, a_source, a_overrideDuplicates);
		}

		RE::BSFixedString nextKey(std::int32_t a_obj, RE::BSFixedString a_previousKey, RE::BSFixedString a_endKey)
		{
			return ApiStorage::get().JMap_nextKey(ApiStorage::get().defaultDomain, a_obj, a_previousKey, a_endKey);
		}

		RE::BSFixedString getNthKey(std::int32_t a_obj, std::int32_t a_keyIndex)
		{
			return ApiStorage::get().JMap_getNthKey(ApiStorage::get().defaultDomain, a_obj, a_keyIndex);
		}
	}
}