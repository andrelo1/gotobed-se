#pragma once

template<class T>
std::string to_str(T const&);
template<>
std::string to_str(RE::FormID const& a_id);
template<>
std::string to_str(RE::TESForm* const& a_form);

template<class T>
T from_str(std::string const& a_str);
template<>
RE::FormID from_str(std::string const& a_str);
template<>
RE::TESForm* from_str(std::string const& a_str);