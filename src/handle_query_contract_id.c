#include "poap_plugin.h"

void handle_query_contract_id(ethQueryContractID_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;

    strlcpy(msg->name, PLUGIN_NAME, msg->nameLength);

    switch (context->selectorIndex) {
        case MINT_TOKEN:
            strlcpy(msg->version, "Mint", msg->versionLength);
            break;
        default:
            PRINTF("Selector index: %d not supported\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }
    msg->result = ETH_PLUGIN_RESULT_OK;
}
