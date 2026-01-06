#include "export.hpp"
#include "steam/steam_api.h"
#include <iostream>

extern "C" {

EXPORT bool sl_GetDLCDataByIndex(int i_dlc, unsigned int app_id, bool available, char name, int name_buf_size) {
    return SteamApps()->BGetDLCDataByIndex(i_dlc, &app_id, &available, &name, name_buf_size);
}

// Checks if app_id is installed locally, this does not check if the user OWNS the app.
EXPORT bool sl_IsAppInstalled(unsigned int app_id) {
    return SteamApps()->BIsAppInstalled(app_id);
}

} // extern "C"