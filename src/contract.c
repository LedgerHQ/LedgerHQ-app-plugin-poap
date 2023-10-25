/*******************************************************************************
 *   Ethereum 2 Deposit Application
 *   (c) 2020 Ledger
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#include <stdint.h>
#include "poap_plugin.h"

// Function: mintToken(uint256 eventId, uint256 tokenId, address receiver, uint256 expirationTime,
// bytes signature)
// Selector: 0xaf68b302
static const uint8_t MINT_TOKEN_SELECTOR[SELECTOR_SIZE] = {0xaf, 0x68, 0xb3, 0x02};

// Array of all the different poap selectors.
const uint8_t *const POAP_SELECTORS[NUM_SELECTORS] = {MINT_TOKEN_SELECTOR};
