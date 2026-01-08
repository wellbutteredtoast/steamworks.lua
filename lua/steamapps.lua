--[[

    'steamapps.lua'

    This is the binding for the ISteamApps interface.
    It provides functions to interact with Steam applications,
    such as checking for DLC ownership, getting app information,
    and managing application states.

    (c) 2026 wellbutteredtoast via GitHub

]]

local steamapps = {}

local ffi = require("ffi")

ffi.cdef[[
    bool sl_IsAppInstalled(unsigned int app_id);
    bool sl_IsSubscribed();
    bool sl_IsSubscribedApp(unsigned int app_id);
    bool sl_IsDLCInstalled(unsigned int app_id);
    bool sl_IsLowViolence();
    bool sl_IsSubscribedFromFamilySharing();
    bool sl_IsSubscribedFromFreeWeekend();
    bool sl_IsTimedTrial(unsigned int seconds_allowed, unsigned int seconds_played);
    bool sl_IsVACBanned();
    int sl_GetAppBuildId();
    unsigned long long sl_GetAppOwner();
    bool sl_SetActiveBeta(const char *beta_name);
    bool sl_GetDlcDownloadProgress(unsigned int app_id, unsigned long long *bytes_downloaded, unsigned long long *bytes_total);
    unsigned int sl_GetEarliestPurchaseUnixTime(unsigned int app_id);
]]

local lib = ffi.load("steamlua")

function steamapps.IsAppInstalled(app_id)
    local installed = ffi.new("bool[1]")
    local result = lib.sl_IsAppInstalled(app_id)
    return result
end

function steamapps.IsSubscribed()
    local result = lib.sl_IsSubscribed()
    return result
end

return steamapps