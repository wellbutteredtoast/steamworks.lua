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

EXPORT void sl_ActivateGameOverlayToStore(unsigned int app_id, unsigned int overlay_flag) {
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
// -> CSteamID GetFriendFromSourceByIndex( CSteamID steamIDSource, int iFriend );
// -> bool GetFriendGamePlayed( CSteamID steamIDFriend, FriendGameInfo_t *pFriendGameInfo );
// -> int GetFriendMessage( CSteamID steamIDFriend, int iMessageID, void *pvData, int cubData, EChatEntryType *peChatEntryType );
// -> const char * GetFriendPersonaName( CSteamID steamIDFriend );
// -> int GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName );
// -> EPersonaState GetFriendPersonaState( CSteamID steamIDFriend );
// -> EFriendRelationship GetFriendRelationship( CSteamID steamIDFriend );
// -> const char * GetFriendRichPresence( CSteamID steamIDFriend, const char *pchKey );
// -> const char * GetFriendRichPresenceKeyByIndex( CSteamID steamIDFriend, int iKey );
// -> int GetFriendRichPresenceKeyCount( CSteamID steamIDFriend );

EXPORT int sl_GetFriendsGroupCount() {
    return SteamFriends()->GetFriendsGroupCount();
}

// -> FriendsGroupID_t GetFriendsGroupIDByIndex( int iFG );
// -> int GetFriendsGroupMembersCount( FriendsGroupID_t friendsGroupID );
// -> void GetFriendsGroupMembersList( FriendsGroupID_t friendsGroupID, CSteamID *pOutSteamIDMembers, int nMembersCount );
// -> const char * GetFriendsGroupName( FriendsGroupID_t friendsGroupID );
// -> int GetFriendSteamLevel( CSteamID steamIDFriend );
// -> int GetLargeFriendAvatar( CSteamID steamIDFriend );
// -> int GetMediumFriendAvatar( CSteamID steamIDFriend );

EXPORT const char *sl_GetPersonaName() {
    return SteamFriends()->GetPersonaName();
}

// -> EPersonaState GetPersonaState();
// -> const char * GetPlayerNickname( CSteamID steamIDPlayer );
// -> int GetSmallFriendAvatar( CSteamID steamIDFriend );
// -> bool HasFriend( CSteamID steamIDFriend, int iFriendFlags );
// -> bool InviteUserToGame( CSteamID steamIDFriend, const char *pchConnectString );
// -> bool IsClanChatAdmin( CSteamID steamIDClanChat, CSteamID steamIDUser );
// -> bool IsClanPublic( CSteamID steamIDClan );
// -> bool IsClanOfficialGameGroup( CSteamID steamIDClan );
// -> bool IsClanChatWindowOpenInSteam( CSteamID steamIDClanChat );
// -> SteamAPICall_t IsFollowing( CSteamID steamID );
// -> SteamAPICall_t JoinClanChatRoom( CSteamID steamIDClan );
// -> bool LeaveClanChatRoom( CSteamID steamIDClan );
// -> bool OpenClanChatWindowInSteam( CSteamID steamIDClanChat );
// -> bool ReplyToFriendMessage( CSteamID steamIDFriend, const char *pchMsgToSend );
// -> SteamAPICall_t RequestClanOfficerList( CSteamID steamIDClan );
// -> void RequestFriendRichPresence( CSteamID steamIDFriend );
// -> bool RequestUserInformation( CSteamID steamIDUser, bool bRequireNameOnly );
// -> bool SendClanChatMessage( CSteamID steamIDClanChat, const char *pchText );
// -> void SetInGameVoiceSpeaking( CSteamID steamIDUser, bool bSpeaking );
// -> bool SetListenForFriendsMessages( bool bInterceptEnabled );
// -> void SetPlayedWith( CSteamID steamIDUserPlayedWith );
// -> bool SetRichPresence( const char *pchKey, const char *pchValue );
// -> SteamAPICall_t RequestEquippedProfileItems( CSteamID steamID);
// -> bool BHasEquippedProfileItem( CSteamID steamID, ECommunityProfileItemType itemType);
// -> bool GetProfileItemPropertyString( CSteamID steamID, ECommunityProfileItemType itemType, ECommunityProfileItemProperty prop);
// -> bool GetProfileItemPropertyUint( CSteamID steamID, ECommunityProfileItemType itemType, ECommunityProfileItemProperty prop);

} // extern "C"