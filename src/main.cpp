#include "jc/jcinit.h"
#include "gotobed/gotobedinit.h"

namespace
{
	constexpr SKSE::PluginVersionData GetPluginVersion()
	{
		SKSE::PluginVersionData version;

		version.PluginVersion({ Version::MAJOR, Version::MINOR, Version::PATCH, 0 });
		version.PluginName(Version::PROJECT);
		version.UsesAddressLibrary(true);

		return version;
	}

	void InitLog()
	{
		auto path = SKSE::log::log_directory();

		if (path) {
			*path /= Version::PROJECT;
			*path += ".log";
			spdlog::set_default_logger(spdlog::basic_logger_mt("default", path->string(), true));
		}

		spdlog::set_level(spdlog::level::trace);
		spdlog::flush_on(spdlog::level::trace);
	}
}

extern "C" __declspec(dllexport) SKSE::PluginVersionData SKSEPlugin_Version{ GetPluginVersion() };

extern "C" __declspec(dllexport) bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface * a_skse)
{
	InitLog();

	spdlog::info("loaded");

	SKSE::Init(a_skse);
#ifndef NOJC
	jc::init();
#endif
	Gotobed::Init();

	return true;
}