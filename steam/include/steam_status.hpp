#ifndef STEAM_STATUS_HPP
#define STEAM_STATUS_HPP

#include <steam/steam_api.h>

static bool gSteamInitalized = false;

#define CHECK_STEAM_INIT() \
    if (!gSteamInitalized) { std::cerr << "Steam is not initalized!" << std::endl; return; }

#endif // STEAM_STATUS_HPP