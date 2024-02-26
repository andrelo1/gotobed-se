#include "formtostr.h"

template<>
std::string to_str(RE::FormID const& a_id) {
	if (a_id == 0) {
		return "";
	}

	if ((a_id & 0xFF000000) == 0xFF000000) {
		return std::format("{:08x}", a_id);
	}

	auto dataHandler = RE::TESDataHandler::GetSingleton();

	if (!dataHandler) {
		return "";
	}

	auto light = (a_id & 0xFF000000) == 0xFE000000;
	auto modIndex = light ? (a_id & 0x00FFF000) >> 12 : a_id >> 24;
	auto mod = light ? dataHandler->LookupLoadedLightModByIndex(modIndex) : dataHandler->LookupLoadedModByIndex(modIndex);

	if (!mod) {
		return "";
	}

	return std::format("{:s}|{:08x}", mod->GetFilename(), light ? (a_id & 0xFFF) : (a_id & 0xFFFFFF));
}

template<>
std::string to_str(RE::TESForm* const& a_form) {
	return a_form ? to_str(a_form->formID) : "";
}

template<>
RE::FormID from_str(std::string const& a_str) {
	if (a_str.empty()) {
		return 0;
	}

	RE::FormID id = 0;
	std::string idstr, modstr;

	auto pos = a_str.find('|');

	if (pos != std::string::npos) {
		modstr = a_str.substr(0, pos);
		idstr = a_str.substr(pos + 1);
	} else {
		idstr = a_str;
	}

	try {
		id = std::stoul(idstr, nullptr, 16);
	} catch (std::exception const& ex) {
		return 0;
	}

	if (modstr.empty()) {
		return id;
	}

	auto dataHandler = RE::TESDataHandler::GetSingleton();

	if (!dataHandler) {
		return 0;
	}

	auto mod = dataHandler->LookupModByName(modstr);

	if (!mod) {
		return 0;
	}

	return mod->IsLight() ? 0xFE000000 + (mod->GetSmallFileCompileIndex() << 12) + (id & 0xFFF) : (mod->GetCompileIndex() << 24) + (id & 0xFFFFFF);
}

template<>
RE::TESForm* from_str(std::string const& a_str) {
	return RE::TESForm::LookupByID(from_str<RE::FormID>(a_str));
}