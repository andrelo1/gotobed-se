#include "JArray.h"
#include "jcapistorage.h"

namespace jc::JArray
{
	using ApiStorage = jc::api::detail::Storage;

	std::int32_t object(void* a_domain)
	{
		return ApiStorage::get().JArray_object(a_domain);
	}

	std::int32_t objectWithSize(void* a_domain, std::int32_t a_size)
	{
		return ApiStorage::get().JArray_objectWithSize(a_domain, a_size);
	}

	std::int32_t objectWithInts(void* a_domain, RE::BSTSmartPointer<RE::BSScript::Array> a_values)
	{
		return ApiStorage::get().JArray_objectWithInts(a_domain, a_values);
	}

	std::int32_t objectWithStrings(void* a_domain, RE::BSTSmartPointer<RE::BSScript::Array> a_values)
	{
		return ApiStorage::get().JArray_objectWithStrings(a_domain, a_values);
	}

	std::int32_t objectWithFloats(void* a_domain, RE::BSTSmartPointer<RE::BSScript::Array> a_values)
	{
		return ApiStorage::get().JArray_objectWithFloats(a_domain, a_values);
	}

	std::int32_t objectWithBooleans(void* a_domain, RE::BSTSmartPointer<RE::BSScript::Array> a_values)
	{
		return ApiStorage::get().JArray_objectWithBooleans(a_domain, a_values);
	}

	std::int32_t objectWithForms(void* a_domain, RE::BSTSmartPointer<RE::BSScript::Array> a_values)
	{
		return ApiStorage::get().JArray_objectWithForms(a_domain, a_values);
	}

	std::int32_t subArray(void* a_domain, std::int32_t a_obj, std::int32_t a_startIndex, std::int32_t a_endIndex)
	{
		return ApiStorage::get().JArray_subArray(a_domain, a_obj, a_startIndex, a_endIndex);
	}

	void addFromArray(void* a_domain, std::int32_t a_obj, std::int32_t a_source, std::int32_t a_insertAtIndex)
	{
		ApiStorage::get().JArray_addFromArray(a_domain, a_obj, a_source, a_insertAtIndex);
	}

	void addFromFormList(void* a_domain, std::int32_t a_obj, RE::BGSListForm* a_source, std::int32_t a_insertAtIndex)
	{
		ApiStorage::get().JArray_addFromFormList(a_domain, a_obj, a_source, a_insertAtIndex);
	}

	std::int32_t getInt(void* a_domain, std::int32_t a_obj, std::int32_t a_index, std::int32_t a_default)
	{
		return ApiStorage::get().JArray_getInt(a_domain, a_obj, a_index, a_default);
	}

	float getFlt(void* a_domain, std::int32_t a_obj, std::int32_t a_index, float a_default)
	{
		return ApiStorage::get().JArray_getFlt(a_domain, a_obj, a_index, a_default);
	}

	RE::BSFixedString getStr(void* a_domain, std::int32_t a_obj, std::int32_t a_index, RE::BSFixedString a_default)
	{
		return ApiStorage::get().JArray_getStr(a_domain, a_obj, a_index, a_default);
	}

	std::int32_t getObj(void* a_domain, std::int32_t a_obj, std::int32_t a_index, std::int32_t a_default)
	{
		return ApiStorage::get().JArray_getObj(a_domain, a_obj, a_index, a_default);
	}

	RE::TESForm* getForm(void* a_domain, std::int32_t a_obj, std::int32_t a_index, RE::TESForm* a_default)
	{
		return ApiStorage::get().JArray_getForm(a_domain, a_obj, a_index, a_default);
	}

	std::int32_t findInt(void* a_domain, std::int32_t a_obj, std::int32_t a_value, std::int32_t a_searchStartIndex)
	{
		return ApiStorage::get().JArray_findInt(a_domain, a_obj, a_value, a_searchStartIndex);
	}

	std::int32_t findFlt(void* a_domain, std::int32_t a_obj, float a_value, std::int32_t a_searchStartIndex)
	{
		return ApiStorage::get().JArray_findFlt(a_domain, a_obj, a_value, a_searchStartIndex);
	}

	std::int32_t findStr(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_value, std::int32_t a_searchStartIndex)
	{
		return ApiStorage::get().JArray_findStr(a_domain, a_obj, a_value, a_searchStartIndex);
	}

	std::int32_t findObj(void* a_domain, std::int32_t a_obj, std::int32_t a_value, std::int32_t a_searchStartIndex)
	{
		return ApiStorage::get().JArray_findObj(a_domain, a_obj, a_value, a_searchStartIndex);
	}

	std::int32_t findForm(void* a_domain, std::int32_t a_obj, RE::TESForm* a_value, std::int32_t a_searchStartIndex)
	{
		return ApiStorage::get().JArray_findForm(a_domain, a_obj, a_value, a_searchStartIndex);
	}

	void setInt(void* a_domain, std::int32_t a_obj, std::int32_t a_index, std::int32_t a_value)
	{
		ApiStorage::get().JArray_setInt(a_domain, a_obj, a_index, a_value);
	}

	void setFlt(void* a_domain, std::int32_t a_obj, std::int32_t a_index, float a_value)
	{
		ApiStorage::get().JArray_setFlt(a_domain, a_obj, a_index, a_value);
	}

	void setStr(void* a_domain, std::int32_t a_obj, std::int32_t a_index, RE::BSFixedString a_value)
	{
		ApiStorage::get().JArray_setStr(a_domain, a_obj, a_index, a_value);
	}

	void setObj(void* a_domain, std::int32_t a_obj, std::int32_t a_index, std::int32_t a_value)
	{
		ApiStorage::get().JArray_setObj(a_domain, a_obj, a_index, a_value);
	}

	void setForm(void* a_domain, std::int32_t a_obj, std::int32_t a_index, RE::TESForm* a_value)
	{
		ApiStorage::get().JArray_setForm(a_domain, a_obj, a_index, a_value);
	}

	void addInt(void* a_domain, std::int32_t a_obj, std::int32_t a_value, std::int32_t a_index)
	{
		ApiStorage::get().JArray_addInt(a_domain, a_obj, a_value, a_index);
	}

	void addFlt(void* a_domain, std::int32_t a_obj, float a_value, std::int32_t a_index)
	{
		ApiStorage::get().JArray_addFlt(a_domain, a_obj, a_value, a_index);
	}

	void addStr(void* a_domain, std::int32_t a_obj, RE::BSFixedString a_value, std::int32_t a_index)
	{
		ApiStorage::get().JArray_addStr(a_domain, a_obj, a_value, a_index);
	}

	void addObj(void* a_domain, std::int32_t a_obj, std::int32_t a_value, std::int32_t a_index)
	{
		ApiStorage::get().JArray_addObj(a_domain, a_obj, a_value, a_index);
	}

	void addForm(void* a_domain, std::int32_t a_obj, RE::TESForm* a_value, std::int32_t a_index)
	{
		ApiStorage::get().JArray_addForm(a_domain, a_obj, a_value, a_index);
	}

	std::int32_t count(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JArray_count(a_domain, a_obj);
	}

	void clear(void* a_domain, std::int32_t a_obj)
	{
		ApiStorage::get().JArray_clear(a_domain, a_obj);
	}

	void eraseIndex(void* a_domain, std::int32_t a_obj, std::int32_t a_index)
	{
		ApiStorage::get().JArray_eraseIndex(a_domain, a_obj, a_index);
	}

	void eraseRange(void* a_domain, std::int32_t a_obj, std::int32_t a_first, std::int32_t a_last)
	{
		ApiStorage::get().JArray_eraseRange(a_domain, a_obj, a_first, a_last);
	}

	std::int32_t valueType(void* a_domain, std::int32_t a_obj, std::int32_t a_index)
	{
		return ApiStorage::get().JArray_valueType(a_domain, a_obj, a_index);
	}

	void swapItems(void* a_domain, std::int32_t a_obj, std::int32_t a_index1, std::int32_t a_index2)
	{
		ApiStorage::get().JArray_swapItems(a_domain, a_obj, a_index1, a_index2);
	}

	std::int32_t sort(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JArray_sort(a_domain, a_obj);
	}

	std::int32_t unique(void* a_domain, std::int32_t a_obj)
	{
		return ApiStorage::get().JArray_unique(a_domain, a_obj);
	}

	bool writeToIntegerPArray(void* a_domain, std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx, std::int32_t a_stopWriteAtIdx, std::int32_t a_readIdx, std::int32_t a_defaultRead)
	{
		return ApiStorage::get().JArray_writeToIntegerPArray(a_domain, a_obj, a_targetArray, a_stopWriteAtIdx, a_stopWriteAtIdx, a_readIdx, a_defaultRead);
	}

	bool writeToFloatPArray(void* a_domain, std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx, std::int32_t a_stopWriteAtIdx, std::int32_t a_readIdx, float a_defaultRead)
	{
		return ApiStorage::get().JArray_writeToFloatPArray(a_domain, a_obj, a_targetArray, a_writeAtIdx, a_stopWriteAtIdx, a_readIdx, a_defaultRead);
	}

	bool writeToFormPArray(void* a_domain, std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx, std::int32_t a_stopWriteAtIdx, std::int32_t a_readIdx, RE::TESForm* a_defaultRead)
	{
		return ApiStorage::get().JArray_writeToFormPArray(a_domain, a_obj, a_targetArray, a_writeAtIdx, a_stopWriteAtIdx, a_readIdx, a_defaultRead);
	}

	bool writeToStringPArray(void* a_domain, std::int32_t a_obj, RE::BSTSmartPointer<RE::BSScript::Array> a_targetArray, std::int32_t a_writeAtIdx, std::int32_t a_stopWriteAtIdx, std::int32_t a_readIdx, RE::BSFixedString a_defaultRead)
	{
		return ApiStorage::get().JArray_writeToStringPArray(a_domain, a_obj, a_targetArray, a_writeAtIdx, a_stopWriteAtIdx, a_readIdx, a_defaultRead);
	}
}