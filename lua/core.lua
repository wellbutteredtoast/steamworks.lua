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
    bool sl_init();
    void sl_shutdown();
    bool sl_restart_app_if_necessary(unsigned int app_id);
    void sl_run_callbacks();
    void sl_set_minidump_comment(const char* comment);
    void sl_write_minidump(unsigned int except_code, void* except_info, unsigned int build_id);
]]

local lib = ffi.load("steamlua")

function core.steam_init()
    return lib.sl_init()
end

function core.steam_shutdown()
    lib.sl_shutdown()
end

function core.restart_app_if_necessary(app_id)
    if app_id == nil or app_id < 0 then
        print("app_id provided is not valid.")
        return nil
    end

    return lib.sl_restart_app_if_necessary(app_id)
end

function core.run_callbacks()
    lib.sl_run_callbacks()
end

function core.set_minidump_comment(comment)
    if comment == nil or type(comment) ~= "string" then
        print("comment provided is not valid.")
        return
    end

    lib.sl_set_minidump_comment(comment)
end

function core.write_minidump(except_code, except_info, build_id)
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

    lib.sl_write_minidump(except_code, except_info, build_id)
end

return core