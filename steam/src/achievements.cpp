#include "export.hpp"
#include "steam/steam_api.h"
#include <iostream>

// Note: this also handles some aspects of SteamUserStats() found in ISteamUserStats
//       refer to Valve's documentation for more details on this class

extern "C" {

// The user_id should not change during runtime. That's... really bad.
static CSteamID user_id = SteamUser()->GetSteamID();

EXPORT bool sl_RequestUserStats() {
    return SteamUserStats()->RequestUserStats(user_id);
}

// Note: achievements_too defaults to false to prevent accidental resets of achievements.
EXPORT bool sl_ResetAllStats(bool achievements_too=false)  {
    return SteamUserStats()->ResetAllStats(achievements_too);
}

} // extern "C"