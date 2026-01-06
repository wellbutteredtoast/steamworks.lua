// steam/src/core.cpp
//
// This is the core, this handles init and shutdown of SteamAPI.
// This doesn't have a header file associated with it.

#include "export.hpp"
#include "steam/steam_api.h"
#include <iostream>

extern "C" {

// Initializes the SteamAPI for use.
EXPORT bool sl_init() {
    return SteamAPI_Init();
}

// Shuts down the SteamAPI.
EXPORT void sl_shutdown() {
    SteamAPI_Shutdown();
}

// Note: if you use SteamDRM, this function is not needed.
EXPORT bool sl_restart_app_if_necessary(unsigned int app_id) {
    return SteamAPI_RestartAppIfNecessary(app_id);
}

// Handles Steam callbacks: seek out Steamworks documentation for more info.
EXPORT void sl_run_callbacks() {
    SteamAPI_RunCallbacks();
}

// Sets minidump comment (untested)
EXPORT void sl_set_minidump_comment(const char* comment) {
    std::cout << "This function only works on 32bit Windows.\nThis will not work anywhere else!" << std::endl;
    SteamAPI_SetMiniDumpComment(comment);
}

// Writes a minidump (untested)
EXPORT void sl_write_minidump(unsigned int except_code, void* except_info, unsigned int build_id) {
    std::cout << "This function only works on 32bit Windows.\nThis will not work anywhere else!" << std::endl;
    SteamAPI_WriteMiniDump(except_code, except_info, build_id);
}

} // extern "C"
