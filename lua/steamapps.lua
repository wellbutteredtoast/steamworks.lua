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
    bool sl_get_dlc_data_by_index(int i_dlc, unsigned int* app_id, bool* available);
    bool sl_is_app_installed(unsigned int app_id);
]]

local lib = ffi.load("steamlua")

function steamapps.get_dlc_data_by_idx(dlc_index)
    -- not yet implemented, error!
    return nil, "getDLCDataByIndex is not yet implemented."
end

function steamapps.is_app_installed(app_id)
    local installed = ffi.new("bool[1]")
    local result = lib.sl_is_app_installed(app_id)
    return result
end

return steamapps