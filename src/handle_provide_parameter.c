#include "poap_plugin.h"

// Copy token sent parameter to token_id
static void handle_token(const ethPluginProvideParameter_t *msg, context_t *context) {
    copy_parameter(context->token_id, msg->parameter, PARAMETER_LENGTH);
}

static void handle_beneficiary(const ethPluginProvideParameter_t *msg, context_t *context) {
    memset(context->beneficiary, 0, sizeof(context->beneficiary));
    memcpy(context->beneficiary,
           &msg->parameter[PARAMETER_LENGTH - ADDRESS_LENGTH],
           sizeof(context->beneficiary));
    PRINTF("BENEFICIARY: %.*H\n", ADDRESS_LENGTH, context->beneficiary);
}

static void handle_mint_token(ethPluginProvideParameter_t *msg, context_t *context) {
    switch (context->next_param) {
        case EVENT_ID:
            context->next_param = TOKEN;
            break;
        case TOKEN:  // id of the token received
            handle_token(msg, context);
            context->next_param = BENEFICIARY;
            break;
        case BENEFICIARY:  // to
            handle_beneficiary(msg, context);
            context->next_param = NONE;
            break;
        case NONE:
            break;
        default:
            PRINTF("Param not supported\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

void handle_provide_parameter(ethPluginProvideParameter_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;

    msg->result = ETH_PLUGIN_RESULT_OK;

    switch (context->selectorIndex) {
        case MINT_TOKEN:
            handle_mint_token(msg, context);
            break;
        default:
            PRINTF("Selector Index not supported: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}
