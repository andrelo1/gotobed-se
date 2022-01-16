#pragma once

namespace jc
{
	struct reflection_interface;
	struct domain_interface;

	namespace api::detail
	{
		struct Storage
		{
			static Storage&		get();

			const reflection_interface*	reflectionInterface{ nullptr };
			const domain_interface*		domainInterface{ nullptr };

								// JDB
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

								// JFormDB
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

								// JValue
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

								// JArray
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

											// JMap
			std::int32_t					(*JMap_object)(void*) { nullptr };
			std::int32_t					(*JMap_getInt)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
			float							(*JMap_getFlt)(void*, std::int32_t, RE::BSFixedString, float) { nullptr };
			RE::BSFixedString				(*JMap_getStr)(void*, std::int32_t, RE::BSFixedString, RE::BSFixedString) { nullptr };
			std::int32_t					(*JMap_getObj)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
			RE::TESForm*					(*JMap_getForm)(void*, std::int32_t, RE::BSFixedString, RE::TESForm*) { nullptr };
			void							(*JMap_setInt)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
			void							(*JMap_setFlt)(void*, std::int32_t, RE::BSFixedString, float) { nullptr };
			void							(*JMap_setStr)(void*, std::int32_t, RE::BSFixedString, RE::BSFixedString) { nullptr };
			void							(*JMap_setObj)(void*, std::int32_t, RE::BSFixedString, std::int32_t) { nullptr };
			void							(*JMap_setForm)(void*, std::int32_t, RE::BSFixedString, RE::TESForm*) { nullptr };
			bool							(*JMap_hasKey)(void*, std::int32_t, RE::BSFixedString) { nullptr };
			std::int32_t					(*JMap_valueType)(void*, std::int32_t, RE::BSFixedString) { nullptr };
			std::int32_t					(*JMap_allKeys)(void*, std::int32_t) { nullptr };
			std::vector<RE::BSFixedString>	(*JMap_allKeysPArray)(void*, std::int32_t) { nullptr };
			std::int32_t					(*JMap_allValues)(void*, std::int32_t) { nullptr };
			bool							(*JMap_removeKey)(void*, std::int32_t, RE::BSFixedString) { nullptr };
			std::int32_t					(*JMap_count)(void*, std::int32_t) { nullptr };
			void							(*JMap_clear)(void*, std::int32_t) { nullptr };
			void							(*JMap_addPairs)(void*, std::int32_t, std::int32_t, bool) { nullptr };
			RE::BSFixedString				(*JMap_nextKey)(void*, std::int32_t, RE::BSFixedString, RE::BSFixedString) { nullptr };
			RE::BSFixedString				(*JMap_getNthKey)(void*, std::int32_t, std::int32_t) { nullptr };
		};
	}
}