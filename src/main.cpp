#include "version.h"
#include "init.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace
{
	void InitLog() {
		auto path = SKSE::log::log_directory();

		if (path) {
			*path /= Project::NAME;
			*path += ".log";
			spdlog::set_default_logger(spdlog::basic_logger_mt("default", path->string(), true));
		}

		spdlog::set_level(spdlog::level::info);
		spdlog::flush_on(spdlog::level::info);
	}
}


extern "C" __declspec(dllexport) bool SKSEAPI SKSEPlugin_Query(const SKSE::QueryInterface* a_skse, SKSE::PluginInfo* a_info) {
	a_info->infoVersion = SKSE::PluginInfo::kVersion;
	a_info->name = Project::NAME.data();
	a_info->version = 1;

	return true;
}

extern "C" __declspec(dllexport) bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface* a_skse) {
	InitLog();
	SKSE::Init(a_skse);
	Gotobed::Init();

	return true;
} 