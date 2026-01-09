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
    if type(app_id) ~= "number" then
        error("app_id must be a number", 2)
    end

    local result = lib.sl_IsAppInstalled(app_id)
    return result
end

function steamapps.IsSubscribed()
    local result = lib.sl_IsSubscribed()
    return result
end

function steamapps.IsSubscribedApp(app_id)
    if type(app_id) ~= "number" then
        error("app_id must be a number", 2)
    end

    local result = lib.sl_IsSubscribedApp(app_id)
    return result
end

function steamapps.IsDLCInstalled(app_id)
    if type(app_id) ~= "number" then
        error("app_id must be a number", 2)
    end

    local result = lib.sl_IsDLCInstalled(app_id)
    return result
end

function steamapps.IsLowViolence()
    local result = lib.sl_IsLowViolence()
    return result
end

function steamapps.IsSubscribedFromFamilySharing()
    local result = lib.sl_IsSubscribedFromFamilySharing()
    return result
end

function steamapps.IsSubscribedFromFreeWeekend()
    local result = lib.sl_IsSubscribedFromFreeWeekend()
    return result
end

function steamapps.IsTimedTrial(seconds_allowed, seconds_played)
    if type(seconds_allowed) ~= "number" then
        error("seconds_allowed must be a number", 2)
    end

    if type(seconds_played) ~= "number" then
        error("seconds_played must be a number", 2)
    end

    local result = lib.sl_IsTimedTrial(seconds_allowed, seconds_played)
    return result
end

function steamapps.IsVACBanned()
    local result = lib.sl_IsVACBanned()
    return result
end

function steamapps.GetAppBuildId()
    local result = lib.sl_GetAppBuildId()
    return result
end

function steamapps.GetAppOwner()
    local result = lib.sl_GetAppOwner()
    return result
end

-- NOTE: this is untested!
function steamapps.SetActiveBeta(beta_name)
    if type(beta_name) ~= "string" then
        error("beta_name must be a string", 2)
    end

    local result = lib.sl_SetActiveBeta(beta_name)
    return result
end

return steamapps