# Contributing to steamworks.lua

Thanks for your interest in contributing! 🎉  
This project aims to provide **clean, flat bindings** for the Steamworks SDK, intended for use via LuaJIT FFI (and engines like LÖVE).

## Scope & Philosophy

- This is **not** a full Steamworks binding
- APIs are intentionally flat and C-friendly
- Safety, clarity, and stability matter more than feature count
- Steamworks internals are large — contributions should stay scoped

If you're unsure whether something fits, feel free to open an issue first.

## What Contributions Are Welcome

- Bug fixes
- Improvements to existing bindings
- New bindings for *small, well-defined* Steamworks functionality
- Build system improvements (CMake, platform support)
- Documentation improvements
- Unit Testing & Improvements

## What Is Out of Scope (for now)

- Large async-heavy subsystems (e.g. full Economy / Inventory rewrites)
- Major API redesigns without discussion
- Breaking ABI changes without coordination

## Code Style

- C++ 17 where required by Steamworks headers
- Keep exported APIs **flat** (no C++ types exposed)
- Prefer explicit names over clever abstractions
- No exceptions, RTTI, or STL in exported interfaces
- Always mark code `extern "C" {}` unless it's explicitly a private\* helper
- Public functions in C++ should always be prefixed by `sl_` and be PascalCase.
    * Example: `sl_RestartAppIfNecessary();`

> [!TIP]
> In this context, **private** means it's not exposed to the FFI.

## Building

This project uses CMake (3.25+).  
You must provide a valid Steamworks SDK path via:

```sh
cmake -DSTEAMWORKS_PATH="~/steamworks/sdk"
```

## License

By contributing, you agree that your contributions will be licensed under the same license as the project.