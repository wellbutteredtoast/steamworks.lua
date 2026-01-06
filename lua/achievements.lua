--[[

    'achievements.lua'

    A steamlua submodule for managing Steam Achievements.
    This module provides functions to unlock, check, and manage
    achievements via the Steamworks API.

    (c) 2026 wellbutteredtoast via GitHub

]]

local achievement = {}

local ffi = require("ffi")

ffi.cdef[[
    bool sl_request_current_stats();
    bool sl_reset_all_stats(bool achievements_too);
]]

function achievement.request_current_stats()
    return ffi.C.sl_request_current_stats()
end

function achievement.reset_all_stats(achievements_too)
    if type(achievements_too) ~= "boolean" then
        print("Expected boolean, got " .. type(achievements_too) .. "(reset_all_stats)")
        return nil
    end

    return ffi.C.sl_reset_all_stats(achievements_too)
end

return achievement