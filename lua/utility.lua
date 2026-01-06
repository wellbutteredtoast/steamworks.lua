--[[

    'utility.lua'

    This is just a set of utility functions to check on the internals
    of steamlua's compiled data. Most of the time, you do not need
    to use anything here, but it's available if you need to or want to.

    (c) 2026 wellbutteredtoast via GitHub
]]

local util = {}

local ffi = require("ffi")

ffi.cdef[[

]]

local lib = ffi.load("steamlua")

return util