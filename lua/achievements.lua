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
    bool sl_RequestUserStats();
    bool sl_ResetAllStats(bool achievements_too);
]]

local lib = ffi.load("steamlua")

function achievement.RequestUserStats()
    return lib.sl_RequestUserStats()
end

function achievement.ResetAllStats(achievements_too)
    if type(achievements_too) ~= "boolean" then
        print("Expected boolean, got " .. type(achievements_too) .. "(reset_all_stats)")
        return nil
    end

    return lib.sl_ResetAllStats(achievements_too)
end

return achievement