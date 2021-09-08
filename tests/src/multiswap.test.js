import "core-js/stable";
import "regenerator-runtime/runtime";
import Eth from "@ledgerhq/hw-app-eth";
import { byContractAddress } from "@ledgerhq/hw-app-eth/erc20";
import Zemu from "@zondax/zemu";
import { TransportStatusError } from "@ledgerhq/errors";

const {NANOS_ETH_ELF_PATH, NANOX_ETH_ELF_PATH, NANOS_PARASWAP_LIB, NANOX_PARASWAP_LIB, sim_options_nanos, sim_options_nanox, TIMEOUT} = require("generic.js");

test("Test SimpleSwap", async () => {
  jest.setTimeout(200000);
  const sim = new Zemu(NANOS_ETH_ELF_PATH, NANOS_PARASWAP_LIB);
  try {
    await sim.start(sim_options_nanos);

    let transport = await sim.getTransport();
    const eth = new Eth(transport);

    // Original TX: https://etherscan.io/tx/0xe89743d41a79ab41df4a5bc1ec05aae3b55b17aab96cffceb002997bcc183f1e
    let tx = eth.signTransaction(
        "44'/60'/0'/0/0",
        "f90a7480850bdfd63e00830eeb08941bd435f3c054b6e901b7b108a0ab7617c808677b89055de6a779bbac0000b90a448f00eccb0000000000000000000000000000000000000000000000000000000000000020000000000000000000000000eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee0000000000000000000000000000000000000000000000055de6a779bbac00000000000000000000000000000000000000000000000047ce107590e650f1c9e00000000000000000000000000000000000000000000047e076fa6ca8052c75000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000140000000000000000000000000000000000000000000000000000000000000000b70617261737761702e696f0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000006c0000000000000000000000000a0b86991c6218b36c1d19d4a2e9eb0ce3606eb48000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000600000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000004a0000000000000000000000000ae0eea652303d174e267e4d51f656254d3039f76000000000000000000000000080bf510fcbf18b91105470639e956102293771200000000000000000000000000000000000000000000000000000000000015e000000000000000000000000000000000000000000000000000000000000000a0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000003a00000000000000000000000000000000000000000000000000000000000000020000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000002c0000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000006daea1723962647b7e189d311d757fb7930000000000000000000000001bd435f3c054b6e901b7b108a0ab7617c808677b000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002cc425ad6100000000000000000000000000000000000000000000000309141221032200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000609507290000000000000000000000000000000000000000000000000000000013c54901000000000000000000000000000000000000000000000000000000000000018000000000000000000000000000000000000000000000000000000000000001e00000000000000000000000000000000000000000000000000000000000000024f47261b0000000000000000000000000a0b86991c6218b36c1d19d4a2e9eb0ce3606eb48000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000024f47261b0000000000000000000000000c02aaa39b223fe8d0a0e5c4f27ead9083c756cc2000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000421b730fe699c976e5a4f9427c7bfbfccc436c5d6d18f733247389e7f302f14dcb0306f15ddff604f405b6affe1b43df13bc41180874aa6258935ca533297939e6a30400000000000000000000000000000000000000000000000000000000000000000000000000000000000077bc1a1ba4e9a6df5bdb21f2bbc07b9854e8d1a8000000000000000000000000bc1315cd2671bc498fdab42ae1214068003dc51e000000000000000000000000000000000000000000000000000000000000113000000000000000000000000000000000000000000000000000000000000000a0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000a0000000000000000000000000000000000000000000000000000000000000002000000000000000000000000000000000000000000000000000000000000000200000000000000000000000000000000000000000000000000000000000000002000000000000000000000000eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee000000000000000000000000a0b86991c6218b36c1d19d4a2e9eb0ce3606eb48000000000000000000000000a47c8bf37f92abed4a126bda807a7b7498661acd00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000060000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000200000000000000000000000007b566ec2b0f914e03e508ea2ae591ea2facf713a000000000000000000000000890f4e345b1daed0367a877a1612f86a1f86985f000000000000000000000000000000000000000000000000000000000000271000000000000000000000000000000000000000000000000000000000000000a0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000a000000000000000000000000000000000000000000000000000000000000000020000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000001018080"
      );

    await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot(), 200000);
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickRight();
    await sim.clickBoth();

    await tx;

  } finally {
    await sim.close();
  }
});

// TODO: add those tests

// https://etherscan.io/tx/0xe89743d41a79ab41df4a5bc1ec05aae3b55b17aab96cffceb002997bcc183f1e
// https://etherscan.io/tx/0x2273d6c6ed86759fdd452dd5ef59c29179718b1acf6b7266e4fa641e4ded0362
// https://etherscan.io/tx/0x4c3b661fd93bca785942c7740d3c725ce02b938f9c673df2f251f779d933905b