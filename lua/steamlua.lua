--[[

    'steamlua.lua'

    A Lua library for interacting with the Steamworks API.
    This library manages all facets of the SteamAPI and exposes
    them via a flat C API for use in LuaJIT scripts and Love2D.

    (c) 2026 wellbutteredtoast via GitHub

    This file is the main file you include, this will include the
    submodules and handle all the backend work on its own, *you* as
    the developer just need to require this file and call the
    functions you need! It's like magic!

]]

local steam = {}

return steam