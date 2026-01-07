<!-- copilot-instructions for steamworks.lua -->
# AI Assistant Guidance — steamworks.lua

This repository is a Lua-first binding for Valve's Steamworks SDK. The goal of these notes is to get an AI coding agent immediately productive on common tasks: navigation, builds, edits, and safe modifications.

- **Big picture**: The project exposes Steamworks to Lua via a C/C++ shared library.
  - `steam/` — C/C++ wrapper compiled as a SHARED library (CMake). Contains `src/` and `include/` and links to the Steamworks redistributable (user-supplied).
  - `lua/` — the Lua-facing API and glue code used by consumers (LÖVE-friendly).
  - `examples/`, `docs/` — usage samples and documentation.

- **Key files to inspect**:
  - [README.md](README.md) — high-level project goals and structure.
  - [steam/readme.md](steam/readme.md) — build constraints and SDK requirements.
  - [steam/CMakeLists.txt](steam/CMakeLists.txt) — the authoritative build rules and required variables (notably `STEAMWORKS_PATH`, CMake >= 3.25).
  - `steam/src/*.cpp` and `steam/include/*.hpp` — C++ implementation and exported C API; look for functions prefixed with `sl_` and the `EXPORT` macro.
  - `lua/*.lua` — the Lua public API surface that consumers use.

- **Build & developer workflows** (reproducible from repo files):
  - Prerequisites: `cmake` >= 3.25, a C/C++ toolchain, and the Steamworks SDK downloaded from Valve.
  - Typical build (from repository root):
    ```bash
    cd steam
    mkdir -p build && cd build
    cmake -DSTEAMWORKS_PATH=/path/to/steamworks -DCMAKE_BUILD_TYPE=Release ..
    cmake --build . --config Release
    ```
  - Important: `STEAMWORKS_PATH` must point to the SDK root that contains `public/steam/steam_api.h` or CMake will `FATAL_ERROR`.
  - To enable strict warnings: `-DPEDANTIC_COMPILE=ON` (may make build fail on warnings).

- **Project conventions & patterns** (do not invent new styles without confirmation):
  - Exported C API functions use the `sl_` prefix and are declared in `extern "C" { ... }` blocks (examples: `steam/src/achievements.cpp`).
  - Use the `EXPORT` macro (defined in `steam/include/export.hpp`) when adding bindings.
  - The C++ side relies on Steam API singletons like `SteamUser()` and `SteamUserStats()`; wrapper functions typically call these and forward results to Lua.
  - The shared library is required (not static) due to LÖVE integration and platform SDK constraints.

- **Integration points & external deps**:
  - Steamworks SDK (required at build time) — placed on the host machine and referenced by `STEAMWORKS_PATH`.
  - The code links a platform-specific `steam_api` library/dylib/so via CMake (see `steam/CMakeLists.txt`).

- **What to watch for when editing**:
  - Preserve the `sl_` API names and `EXPORT` markings for any function intended to be callable from Lua.
  - Avoid changing the ABI of exported functions without updating Lua bindings; Lua code expects the names and signatures in `lua/`.
  - Follow existing error-handling patterns used in `steam/src/*.cpp` (there is no unified error subsystem).
  - Do not assume Steamworks headers/libraries are present on CI — tests/builds that require building `steam/` must set `STEAMWORKS_PATH`.

- **Examples to reference in PRs or local edits**:
  - `steam/src/achievements.cpp` — pattern: call Steam API, wrap in `EXPORT` function named `sl_...`.
  - `steam/CMakeLists.txt` — how platform-specific steam_api libs are selected and how compile-time flags are passed.

- **If you need to run or debug locally**:
  - Build the shared library as shown above, then load it into the Lua runtime or LÖVE project that uses these bindings.
  - On macOS, CMake selects `libsteam_api.dylib` from the Steamworks redistributable; ensure Xcode toolchain and run-paths are set appropriately when testing.


