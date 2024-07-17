#pragma once

#include "eth_plugin_interface.h"
#include <string.h>

#define NUM_SELECTORS    1
#define PLUGIN_NAME      "POAP"
#define SELECTOR_SIZE    4
#define PARAMETER_LENGTH 32
#define RUN_APPLICATION  1

typedef enum {
    MINT_TOKEN,
} selector_t;

// Enumeration used to parse the smart contract data.
#define EVENT_ID    0
#define TOKEN       1
#define BENEFICIARY 2
#define NONE        3

typedef enum {
    TOKEN_SCREEN,
    BENEFICIARY_SCREEN,
    ERROR,
} screens_t;

extern const uint8_t *const POAP_SELECTORS[NUM_SELECTORS];

// Shared global memory with Ethereum app. Must be at most 5 * 32 bytes.
typedef struct context_t {
    // For display.
    uint8_t beneficiary[ADDRESS_LENGTH];
    uint8_t token_id[PARAMETER_LENGTH];  // not crypto token dedicated poap token value int number

    // For parsing data.
    uint8_t next_param;

    // For both parsing and display.
    selector_t selectorIndex;
} context_t;

// Piece of code that will check that the above structure is not bigger than 5 * 32. Do not remove
// this check.
_Static_assert(sizeof(context_t) <= 5 * 32, "Structure of parameters too big.");
