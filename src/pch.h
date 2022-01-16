#pragma once

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"
#include <spdlog/sinks/basic_file_sink.h>

using namespace std::literals;

#define DLLEXPORT __declspec(dllexport)

#include "version.h"

#define NOMINMAX
#define NOGDI
#include <windows.h>
#include "Detours/include/detours.h"

#define JC_DOMAIN "GTB_JCDomain"
#include "jc/jc.h"