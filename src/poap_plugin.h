#pragma once

#include "eth_internals.h"
#include "eth_plugin_interface.h"
#include <string.h>

#define NUM_SELECTORS    2
#define PLUGIN_NAME      "POAP"
#define TOKEN_FOUND      1 << 1
#define SELECTOR_SIZE    4
#define PARAMETER_LENGTH 32
#define RUN_APPLICATION  1

typedef enum {
    MINT_TOKEN,
    SAFE_TRANSFER,
} selector_t;

// Enumeration used to parse the smart contract data.
typedef enum {
    EVENT_ID,
    TOKEN,
    BENEFICIARY,
    FROM_ADDRESS,
    NONE,
} parameter;

typedef enum {
    TOKEN_SCREEN,
    BENEFICIARY_SCREEN,
    FROM_ADDRESS_SCREEN,
    WARN_SCREEN,
    ERROR,
} screens_t;

extern const uint8_t *const POAP_SELECTORS[NUM_SELECTORS];

// Shared global memory with Ethereum app. Must be at most 5 * 32 bytes.
typedef struct context_t {
    // For display.
    uint8_t beneficiary[ADDRESS_LENGTH];
    uint8_t from_address[ADDRESS_LENGTH];
    uint8_t token_id[PARAMETER_LENGTH];  // not crypto token dedicated poap token value int number
    char ticker[MAX_TICKER_LEN];

    // For parsing data.
    uint16_t offset;
    uint16_t checkpoint;
    uint8_t skip;
    uint8_t decimals;
    uint8_t next_param;
    uint8_t tokens_found;

    // For both parsing and display.
    selector_t selectorIndex;
} context_t;

// Piece of code that will check that the above structure is not bigger than 5 * 32. Do not remove
// this check.
_Static_assert(sizeof(context_t) <= 5 * 32, "Structure of parameters too big.");

void handle_provide_parameter(void *parameters);
void handle_query_contract_ui(void *parameters);
void handle_init_contract(void *parameters);
void handle_finalize(void *parameters);
void handle_query_contract_id(void *parameters);
