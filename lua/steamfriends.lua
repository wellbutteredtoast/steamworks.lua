--[[

    'steamfriends.lua'

    Submodule for the ISteamFriends interface.
    This provides functions for most of Steams social
    features as well as the overlay.

    (c) 2026 wellbutteredtoast via GitHub

]]

local friends = {}
local ffi = require("ffi")

ffi.cdef[[
    void sl_ActivateGameOverlay(const char *dialog);
    void sl_ActivateGameOverlayInviteDialog();
    void sl_ActivateGameOverlayToStore(unsigned int app_id, unsigned int overlay_flag);
    void sl_ActivateGameOverlayToUser(const char *dialog, unsigned long long steam_id);
    void sl_ActivateGameOverlayToWebPage(const char *url);
    void sl_ClearRichPresence();
    bool sl_CloseClanChatWindowInSteam(unsigned long long steam_id_clan_chat);
    int sl_GetClanCount();
    int sl_GetCoplayFriendCount();
]]

local lib = ffi.load("steamlua")

function friends.ActivateGameOverlay(dialog)
    if type(dialog) ~= "string" then
        error("dialog must be a string", 2)
    end

    lib.sl_ActivateGameOverlay(dialog)
end

function friends.ActivateGameOverlayInviteDialog()
    lib.sl_ActivateGameOverlayInviteDialog()
end

function friends.ActivateGameOverlayToStore(app_id, overlay_flag)
    if type(app_id) ~= "number" then
        error("app_id must be a number", 2)
    end

    overlay_flag = overlay_flag or 0
    lib.sl_ActivateGameOverlayToStore(app_id, overlay_flag)
end

function friends.ActivateGameOverlayToUser(dialog, steam_id)
    if type(dialog) ~= "string" then
        error("dialog must be a string", 2)
    end

    if type(steam_id) ~= "number" then
        error("steam_id must be a number (uint64)", 2)
    end

    lib.sl_ActivateGameOverlayToUser(dialog, steam_id)
end

function friends.ActivateGameOverlayToWebPage(url)
    if type(url) ~= "string" then
        error("url must be a string", 2)
    end

    lib.sl_ActivateGameOverlayToWebPage(url)
end

function friends.ClearRichPresence()
    lib.sl_ClearRichPresence()
end

function friends.CloseClanChatWindowInSteam(steam_id_clan_chat)
    if type(steam_id_clan_chat) ~= "number" then
        error("steam_id_clan_chat must be a number", 2)
    end

    return lib.sl_CloseClanChatWindowInSteam(steam_id_clan_chat)
end

function friends.GetClanCount()
    return lib.sl_GetClanCount()
end

function friends.GetCoplayFriendCount()
    return lib.sl_GetCoplayFriendCount()
end


return friends
