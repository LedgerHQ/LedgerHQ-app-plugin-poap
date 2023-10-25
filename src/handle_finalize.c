#include "poap_plugin.h"

void handle_finalize(ethPluginFinalize_t *msg) {
    msg->uiType = ETH_UI_TYPE_GENERIC;

    // 2 additional screens are required to display the `token and `beneficiary` fields
    msg->numScreens = 2;
    msg->result = ETH_PLUGIN_RESULT_OK;
}
