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
    bool sl_ClearAchievement(const char *achievement_id);
    bool sl_GetAchievement(const char *achievement_id, bool *achieved);
    bool sl_GetAchievementAchievedPercent(const char *achievement_id, float *percent);
]]

local lib = ffi.load("steamlua")

function achievement.RequestUserStats()
    return lib.sl_RequestUserStats()
end

function achievement.ResetAllStats(achievements_too)
    if type(achievements_too) ~= "boolean" then
        print("Expected boolean, got " .. type(achievements_too))
        return nil
    end

    return lib.sl_ResetAllStats(achievements_too)
end

function achievement.ClearAchievement(achievement_id)
    if type(achievement_id) ~= "string" then
        error("AchievementID needs to be a string", 2)
    end

    local achid = ffi.new("bool[1]")
    local result = lib.sl_ClearAchievement(achid)
    return result
end

function achievement.GetAchievement(achievement_id, achieved)
    if type(achievement_id) ~= "string" then
        error("AchievementID needs to be a string", 2)
    end

    if type(achieved) ~= "boolean" then
        error("'achieved' variable must be a boolean", 2)
    end

    local achid_p = ffi.new("char[1]")
    local achieve_p = ffi.new("bool[1]")

    return lib.sl_GetAchievement(achid_p, achieve_p)
end

return achievement