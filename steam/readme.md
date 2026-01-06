# Steamworks C API Wrapper

These are the C / C++ wrappers for the Steamworks API. This is the most technical region of the `steamworks.lua` project as this is where Steamworks is simplified from the **massive** library of C++ down to a handful of C files and a clean API for Lua and LÖVE. These files are compiled into a **dynamic** library. To build this project, you'll need **CMake** installed and updated to at least `3.25`

> [!TIP]
> We cannot compile this into a static library, since that would require linking to the `LOVE.exe` executable, unless you build from LÖVE's source code, this is impossible.

You'll need to provide your own Steamworks, we cannot legally distribute the software. You can download it from Valve directly from their **[Partner Website](https://partner.steamgames.com)**. We've linked it here for ease of access, you'll need valid Steam credentials to access it.