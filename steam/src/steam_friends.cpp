#include "export.hpp"
#include "stub.hpp"
#include "steam/steam_api.h"
#include <iostream>

extern "C" {

// VALVE: Valid options are: "friends", "community", "players", "settings", "officialgamegroup", "stats", "achievements".
EXPORT void sl_ActivateGameOverlay(const char *dialog) {
    STUB_RETURN(void, "Not implemented yet! (sl_ActivateGameOverlay)", nullptr);
}

EXPORT void sl_ActivateGameOverlayInviteDialog() {
    STUB_RETURN(void, "Not implemented yet! (sl_ActivateGameOverlayInviteDialog)", nullptr);

EXPORT void sl_ActivateGameOverlayToStore() {
    STUB_RETURN(void, "Not implemented yet! (sl_ActivateGameOverlayToStore)", nullptr);
}

} // extern "C"