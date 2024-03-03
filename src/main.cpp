#include "plugin.h"
#include "init.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace
{
	constexpr SKSE::PluginVersionData GetPluginVersion() {
		SKSE::PluginVersionData version;

		version.PluginVersion({Plugin::Version::major, Plugin::Version::minor, Plugin::Version::patch, Plugin::Version::build});
		version.PluginName(Plugin::name);
		version.UsesAddressLibrary(true);

		return version;
	}

	void InitLog() {
		std::filesystem::path path;
		auto dir = SKSE::log::log_directory();

		if (dir) {
			path = *dir;
			path /= Plugin::name;
			path += ".log";
		} else {
			path = Plugin::name;
			path += ".log";
		}

		spdlog::set_default_logger(spdlog::basic_logger_mt("default", path.string(), true));
		spdlog::set_level(spdlog::level::info);
		spdlog::flush_on(spdlog::level::info);
	}
}

extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{GetPluginVersion()};

extern "C" __declspec(dllexport) bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface* a_skse) {
	InitLog();
	SKSE::Init(a_skse);
	Gotobed::Init();

	return true;
}