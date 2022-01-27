#ifndef NOJC
#include "jc/jcinit.h"
#endif
#include "gotobed/gotobedinit.h"

extern "C" DLLEXPORT bool SKSEPlugin_Query(const SKSE::QueryInterface* a_skse, SKSE::PluginInfo* a_info)
{
	auto path = SKSE::log::log_directory();

	if (path) {
		*path /= Version::PROJECT;
		*path += ".log";
		spdlog::set_default_logger(spdlog::basic_logger_mt("default", path->string(), true));
	}

	spdlog::set_level(spdlog::level::trace);
	spdlog::flush_on(spdlog::level::trace);

	a_info->infoVersion = SKSE::PluginInfo::kVersion;
	a_info->name = Version::PROJECT;
	a_info->version = Version::MAJOR << 24 | Version::MINOR << 16 | Version::PATCH << 4;

	return true;
}

extern "C" DLLEXPORT bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface * a_skse)
{
	spdlog::info("loaded");

	SKSE::Init(a_skse);
#ifndef NOJC
	jc::init(a_skse);
#endif
	Gotobed::Init();

	return true;
}