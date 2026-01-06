#include "export.hpp"
#include "steam/steam_api.h"
#include <iostream>

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

EXPORT bool sl_ClearAchievement(const char *achievement_id) {
    return SteamUserStats()->ClearAchievement(achievement_id);
}

// -> SteamAPICall_t DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd );
// -> SteamAPICall_t DownloadLeaderboardEntriesForUsers( SteamLeaderboard_t hSteamLeaderboard, CSteamID *prgUsers, int cUsers );
// -> SteamAPICall_t FindLeaderboard( const char *pchLeaderboardName );
// -> SteamAPICall_t FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType );

EXPORT bool sl_GetAchievement(const char *achievement_id, bool *achieved) {
    return SteamUserStats()->GetAchievement(achievement_id, achieved);
}

EXPORT bool sl_GetAchievementAchievedPercent(const char *achievement_id, float *percent) {
    return SteamUserStats()->GetAchievementAchievedPercent(achievement_id, percent);
}

} // extern "C"