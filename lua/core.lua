--[[

    'core.lua'

    This is the core, this handles the fundamental functions
    of the Steamworks API, such as initialization, shutdown,
    user information and some debugging functionality.

    Note: setting and using Steam minidumps are untested.

    (c) 2026 wellbutteredtoast via GitHub

]]

local core = {}

local ffi = require("ffi")

ffi.cdef[[
    bool sl_Init();
    void sl_Shutdown();
    bool sl_RestartAppIfNecessary(unsigned int app_id);
    void sl_RunCallbacks();
    void sl_SetMinidumpComment(const char* comment);
    void sl_WriteMinidump(unsigned int except_code, void* except_info, unsigned int build_id);
    const int sl_GetABIVersion();
    const char *sl_GetVersion();
]]

local lib = ffi.load("steamlua")

function core.SteamInit()
    return lib.sl_Init()
end

function core.SteamShutdown()
    lib.sl_Shutdown()
end

function core.RestartAppIfNecessary(app_id)
    if app_id == nil or app_id < 0 then
        print("app_id provided is not valid.")
        return nil
    end

    return lib.sl_RestartAppIfNecessary(app_id)
end

function core.RunCallbacks()
    lib.sl_RunCallbacks()
end

function core.SetMinidumpComment(comment)
    if comment == nil or type(comment) ~= "string" then
        print("comment provided is not valid.")
        return nil
    end

    lib.sl_SetMinidumpComment(comment)
end

function core.WriteMinidump(except_code, except_info, build_id)
    if except_code == nil or type(except_code) ~= "number" then
        print("except_code provided is not valid.")
        return
    end

    if except_info == nil then
        print("except_info provided is not valid.")
        return
    end

    if build_id == nil or type(build_id) ~= "number" then
        print("build_id provided is not valid.")
        return
    end

    lib.sl_WriteMinidump(except_code, except_info, build_id)
end

function core.GetABIVersion()
    return lib.sl_GetABIVersion()
end

function core.GetVersion()
    return lib.sl_GetVersion()
end

return core