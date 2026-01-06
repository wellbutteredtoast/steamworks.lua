#include "export.hpp"
#include "steam/steam_api.h"
#include <iostream>

extern "C" {

// VALVE: Valid options are: "friends", "community", "players", "settings", "officialgamegroup", "stats", "achievements".
EXPORT void sl_ActivateGameOverlay(const char *dialog) {
    std::cerr << "Not implemented yet! (sl_ActivateGameOverlay)" << std::endl;
    return;
}

EXPORT void sl_ActivateGameOverlayInviteDialog() {
    std::cerr << "Not implemented yet! (sl_ActivateGameOverlayInviteDialog)" << std::endl;
    return;
}

EXPORT void sl_ActivateGameOverlayToStore() {
    std::cerr << "Not implemented yet! (sl_ActivateGameOverlayToStore)" << std::endl;
    return;
}

} // extern "C"