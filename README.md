# steamworks.lua

**steamworks.lua** is a Lua-first, LÖVE-friendly binding for Valve's Steamworks SDK.

It aims to make integrating key SteamAPI features *painless* and *fast*. No need to wrangle together a bridge from SteamAPIs **C++** to something that Lua can understand. This project handles all of that for you!

## Goals
 - Idiomatic Lua APIs
 - Minimal friction for LÖVE projects
 - Clear and clean errors and docs
 - Cross-platform support

## Non-goals
 - Redistributing Steamworks or other Valve properties
 - Replacing Steamworks or Steam
 - Obscuring Steamworks concepts

steamworks.lua is a binding, not an attempt at reimplementation.

## Project Structure

```
steamworks.lua/
├─ steam/         # C / C++ wrapper over Steamworks SDK
├─ lua/           # Lua bindings and public APIs
├─ examples/      # Minimal working examples
├─ docs/          # Detailed API documentation
```
This separation allows contributors to work on *individual* layers without touching the entire codebase.

## Project Status

⚠️ **Early Development**

Our APIs are not stable and some code may not be tested fully when pushed to `master`. Expect changes to break periodically while we stabilize!

Initial focus is on the core aspects of Steamworks:
 - Init & Shutdown
 - Achievements
 - Stats
 - Functioning Steam Overlay

## Legal Note

Steamworks is a proprietary SDK owned by Valve. \
This project does not bundle or redistribute the Steamworks SDK.

You must obtain the SDK directly from Valve and comply with their SDK Access Terms.

> [!NOTE]
> More of the README is coming soon!
