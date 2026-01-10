// steam/src/core.cpp
//
// This is the core, this handles init and shutdown of SteamAPI.
// This doesn't have a header file associated with it.

#include "export.hpp"
#include "version.hpp"
#include "stub.hpp"
#include "steam_status.hpp"
#include <steam/steam_api.h>
#include <iostream>
#include <cstdlib>

extern "C" {

// Helper: Get the internal ABI version number
EXPORT const int sl_GetABIVersion() {
    return LUASTEAM_ABI_VERSION;
}

// Helper: Get the human friendly Semantic Version version of the project
EXPORT const char *sl_GetVersion() {
    return LUASTEAM_VERSION;
}

// Helper: Check the SteamAPI status
EXPORT bool sl_GetSteamStatus() {
    return gSteamInitalized;
}

// Initializes the SteamAPI for use.
EXPORT bool sl_Init() {
    if (SteamAPI_Init()) {
        gSteamInitalized = true;
    } else {
        gSteamInitalized = false;
    }

    return gSteamInitalized;
}

// Shuts down the SteamAPI.
EXPORT void sl_Shutdown() {
    SteamAPI_Shutdown();
}

// Note: if you use SteamDRM, this function is not needed.
EXPORT bool sl_RestartAppIfNecessary(unsigned int app_id) {
    return SteamAPI_RestartAppIfNecessary(app_id);
}

// Handles Steam callbacks: seek out Steamworks documentation for more info.
EXPORT void sl_RunCallbacks() {
    if (!gSteamInitalized) {
        abort();
    }
    
    SteamAPI_RunCallbacks();
}

// Sets minidump comment (untested)
EXPORT void sl_SetMiniDumpComment(const char* comment) {
    STUB_WARN("This function only works on x86 (32bit) Windows!");
    SteamAPI_SetMiniDumpComment(comment);
}

// Writes a minidump (untested)
EXPORT void sl_WriteMiniDump(unsigned int except_code, void* except_info, unsigned int build_id) {
    STUB_WARN("This function only works on x86 (32bit) Windows!");
    SteamAPI_WriteMiniDump(except_code, except_info, build_id);
}

} // extern "C"
