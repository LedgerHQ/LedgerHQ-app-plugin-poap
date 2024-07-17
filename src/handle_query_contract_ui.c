#include <stdbool.h>
#include "poap_plugin.h"

// Set UI for "Token" screen.
static bool set_token_ui(ethQueryContractUI_t *msg, context_t *context) {
    strlcpy(msg->title, "Token", msg->titleLength);

    return amountToString(context->token_id,
                          sizeof(context->token_id),
                          0,
                          "",
                          msg->msg,
                          msg->msgLength);
}

// Set UI for "Beneficiary" screen.
static bool set_beneficiary_ui(ethQueryContractUI_t *msg, context_t *context) {
    strlcpy(msg->title, "Beneficiary", msg->titleLength);

    msg->msg[0] = '0';
    msg->msg[1] = 'x';

    return getEthAddressStringFromBinary(context->beneficiary,
                                         msg->msg + 2,
                                         0);
}

// Helper function that returns the enum corresponding to the screen that should be displayed.
static screens_t get_screen(const ethQueryContractUI_t *msg) {
    uint8_t index = msg->screenIndex;

    switch (index) {
        case 0:
            return TOKEN_SCREEN;
        case 1:
            return BENEFICIARY_SCREEN;
        default:
            return ERROR;
    }
}

void handle_query_contract_ui(ethQueryContractUI_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;
    bool ret = false;

    memset(msg->title, 0, msg->titleLength);
    memset(msg->msg, 0, msg->msgLength);

    screens_t screen = get_screen(msg);

    switch (screen) {
        case TOKEN_SCREEN:
            ret = set_token_ui(msg, context);
            break;
        case BENEFICIARY_SCREEN:
            ret = set_beneficiary_ui(msg, context);
            break;
        default:
            PRINTF("Received an invalid screenIndex\n");
    }
    msg->result = ret ? ETH_PLUGIN_RESULT_OK : ETH_PLUGIN_RESULT_ERROR;
}
