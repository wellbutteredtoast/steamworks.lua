#include "export.hpp"
#include "stub.hpp"
#include "steam/steam_api.h"
#include <iostream>

extern "C" {

// Valve: Valid options are: "friends", "community", "players", "settings", "officialgamegroup", "stats", "achievements".
EXPORT void sl_ActivateGameOverlay(const char *dialog) {
    STUB_RETURN(void, "Not implemented yet! (sl_ActivateGameOverlay)", nullptr);
}

EXPORT void sl_ActivateGameOverlayInviteDialog() {
    STUB_RETURN(void, "Not implemented yet! (sl_ActivateGameOverlayInviteDialog)", nullptr);
}

EXPORT void sl_ActivateGameOverlayToStore(unsigned int app_id, unsigned int overlay_store_flag) {
    STUB_RETURN(void, "Not implemented yet! (sl_ActivateGameOverlayToStore)", nullptr);
}

EXPORT void sl_ActivateGameOverlayToUser(const char *dialog, unsigned long long steam_id) {
    STUB_RETURN(void, "Not implemented yet! (sl_ActivateGameOverlayToUser)", nullptr);
}

EXPORT void sl_ActivateOverlayToWebPage(const char *url) {
    STUB_RETURN(void, "Not implemented yet! (sl_ActivateOverlayToWebPage)", nullptr);
}

EXPORT void sl_ClearRichPresence() {
    SteamFriends()->ClearRichPresence();
}

EXPORT bool sl_CloseClanChatWindowInSteam(unsigned long long steam_id_clan_chat) {
    STUB_RETURN(bool, "Not implemented yet! (sl_CloseClanChatWindowInSteam)", false);
}

// Cannot yet be done, do not attempt to implement yet!
// -> SteamAPICall_t DownloadClanActivityCounts( CSteamID *psteamIDClans, int cClansToRequest );
// -> SteamAPICall_t EnumerateFollowingList( uint32 unStartIndex );
// -> CSteamID GetChatMemberByIndex( CSteamID steamIDClan, int iUser );
// -> bool GetClanActivityCounts( CSteamID steamIDClan, int *pnOnline, int *pnInGame, int *pnChatting );
// -> int GetClanChatMessage( CSteamID steamIDClanChat, int iMessage, void *prgchText, int cchTextMax, EChatEntryType *peChatEntryType, CSteamID *psteamidChatter );

EXPORT int sl_GetClanCount() {
    return SteamFriends()->GetClanCount();
}

// -> const char * GetClanName( CSteamID steamIDClan );
// -> CSteamID GetClanOfficerByIndex( CSteamID steamIDClan, int iOfficer );
// -> int GetClanOfficerCount( CSteamID steamIDClan );
// -> CSteamID GetClanOwner( CSteamID steamIDClan );
// -> const char * GetClanTag( CSteamID steamIDClan );
// -> CSteamID GetCoplayFriend( int iCoplayFriend );

EXPORT int sl_GetCoplayFriendCount() {
    return SteamFriends()->GetCoplayFriendCount();
}

// -> SteamAPICall_t GetFollowerCount( CSteamID steamID );
// -> CSteamID GetFriendByIndex( int iFriend, int iFriendFlags );
// -> AppId_t GetFriendCoplayGame( CSteamID steamIDFriend );
// -> int GetFriendCoplayTime( CSteamID steamIDFriend );
// -> int GetFriendCount( int iFriendFlags );
// -> int GetFriendCountFromSource( CSteamID steamIDSource );


} // extern "C"