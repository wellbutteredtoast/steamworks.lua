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