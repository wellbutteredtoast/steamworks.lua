#include "export.hpp"
#include "steam/steam_api.h"
#include <iostream>

extern "C" {

// Checks if app_id is installed locally, this does not check if the user OWNS the app.
EXPORT bool sl_IsAppInstalled(unsigned int app_id) {
    return SteamApps()->BIsAppInstalled(app_id);
}

// Checks if the current user is subscribed to the game (has a license to play)
EXPORT bool sl_IsSubscribed() {
    return SteamApps()->BIsSubscribed();
}

} // extern "C"