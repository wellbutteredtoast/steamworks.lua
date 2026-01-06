#include "export.hpp"
#include "stub.hpp"
#include "steam/steam_api.h"
#include <iostream>

extern "C" {

// Checks if app_id is installed locally, this does not check if the user OWNS the app.
EXPORT bool sl_IsAppInstalled(unsigned int app_id) {
    return SteamApps()->BIsAppInstalled(app_id);
}

// Checks if the current user is subscribed to the game (has a license to play)
EXPORT bool sl_IsSubscribed() {
    return SteamApps()->BIsSubscribed();
}

// Valve: Only use this if you need to check ownership of another game related to yours, a demo for example.
EXPORT bool sl_IsSubscribedApp(unsigned int app_id) {
    return SteamApps()->BIsSubscribedApp(app_id);
}

EXPORT bool sl_IsDLCInstalled(unsigned int app_id) {
    return SteamApps()->BIsDLCInstalled(app_id);
}

EXPORT bool sl_IsLowViolence() {
    return SteamApps()->BIsLowViolence();
}

EXPORT bool sl_IsSubscribedFromFamilySharing() {
    return SteamApps()->BIsSubscribedFromFamilySharing();
}

EXPORT bool sl_IsSubscribedFromFreeWeekend() {
    return SteamApps()->BIsSubscribedFromFreeWeekend();
}

EXPORT bool sl_IsTimedTrial(unsigned int seconds_allowed, unsigned int seconds_played) {
    STUB_RETURN(bool, "sl_IsTimedTrial is not implemented yet!", false);
}

// Note: This will check for any Valve Anti-Cheat bans on any VAC-secure games.
EXPORT bool sl_IsVACBanned() {
    return SteamApps()->BIsVACBanned();
}

// Note: Defaults to 0 if you're not running a build downloaded from steam.
EXPORT int sl_GetAppBuildID() {
    return SteamApps()->GetAppBuildID();
}

EXPORT unsigned long long sl_GetAppOwner() {
    STUB_RETURN(unsigned long long, "Not implemented yet! (sl_GetAppOwner)", 0);
}

EXPORT const char *sl_GetAvailableGameLanguages() {
    STUB_RETURN(const char*, "Not implemented yet! (sl_GetAvailableGameLanguages)", nullptr);
}

EXPORT bool sl_GetCurrentBetaName(char *name, int name_buffer_size) {
    STUB_RETURN(bool, "Not implemented yet! (sl_GetCurrentBetaName)", false);
}

EXPORT int sl_GetNumBetas(int *available, int *private) {
    STUB_RETURN(int, "Not implemented yet! (sl_GetNumBetas)", 0);
}

// Note: variable names taken stright out of Steamworks, rename before working on!
EXPORT int sl_GetBetaInfo(int iBetaIndex, uint32 *punFlags, uint32 *punBuildID, char *pchBetaName, int cchBetaName, char *pchDescription, int cchDescription) {
    STUB_RETURN(int, "Not implemented yet! (sl_GetBetaInfo)", 0);
}

EXPORT bool sl_SetActiveBeta(const char *beta_name) {
    return SteamApps()->SetActiveBeta(beta_name);
}

EXPORT const char* sl_GetCurrentGameLanguage() {
    STUB_RETURN(const char*, "sl_GetCurrentGameLanguage is not implemented yet!", nullptr);
}

EXPORT unsigned int sl_GetDLCCount() {
    STUB_RETURN(unsigned int, "sl_GetDLCCount is not implemented yet!", 0);
}

EXPORT bool sl_GetDlcDownloadProgress(unsigned int app_id, unsigned long long *bytes_downloaded, unsigned long long *bytes_total) {
    return SteamApps()->GetDlcDownloadProgress(app_id, bytes_downloaded, bytes_total);
}

EXPORT unsigned int sl_GetEarliestPurchaseUnixTime(unsigned int app_id) {
    return SteamApps()->GetEarliestPurchaseUnixTime(app_id);
}

// The following functions won't be implemented yet:
// -> SteamAPICall_t GetFileDetails( const char*pszFileName );
// -> uint32 GetInstalledDepots( AppId_t appID, DepotId_t *pvecDepots, uint32 cMaxDepots );
// -> int GetLaunchCommandLine( char *pszCommandLine, int cubCommandLine );
// -> const char * GetLaunchQueryParam( const char *pchKey );
// -> void InstallDLC( AppId_t nAppID );
// -> bool MarkContentCorrupt( bool bMissingFilesOnly );
// -> void RequestAllProofOfPurchaseKeys();
// -> void RequestAppProofOfPurchaseKey( AppId_t nAppID );
// -> void UninstallDLC( AppId_t nAppID );
//
// All of these are complex beyond the current scope of the project. Do not implement yet!
// Date: 5 January, 2026 @ 23:40 UTC-3:30

} // extern "C"