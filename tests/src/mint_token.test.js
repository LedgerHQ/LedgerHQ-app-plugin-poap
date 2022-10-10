import { processTest, populateTransaction } from "./test.fixture";

const contractName = "PoapDelegatedMint";
const testLabel = "Mint Token"; // <= Name of the test
const testDirSuffix = "mint_token"; // <= directory to compare device snapshots to
const signedPlugin = false;
const testNetwork = "ethereum";

const contractAddr = "0x0bb4d3e88243f4a057db77341e6916b0e449b158";
const chainID = 1;

// From : https://etherscan.io/tx/0x1b661fb1ed634031b13d7532fa2982f95c73b3c926ee91960d5c7fcca0ff581a
const inputData = "0xaf68b3020000000000000000000000000000000000000000000000000000000000006cf600000000000000000000000000000000000000000000000000000000003f150200000000000000000000000081168c14e5a89f60b30e9a7f82a229406a64369d000000000000000000000000000000000000000000000000000000006221db8200000000000000000000000000000000000000000000000000000000000000a000000000000000000000000000000000000000000000000000000000000000418d0ac5f026acfc0cc918f254c6800da31d530f81fc4a2f5db1560325a8603cbc3d99171f880ea7ca8a58f015babdfdc35c57b4b71c13e7a287d0f157789443441b00000000000000000000000000000000000000000000000000000000000000";

const serializedTx = populateTransaction(contractAddr, inputData, chainID);


const devices = [
  {
    name: "nanos",
    label: "Nano S",
    steps: 7, // <= Define the number of steps for this test case and this device
  },
  {
    name: "nanox",
    label: "Nano X",
    steps: 5, // <= Define the number of steps for this test case and this device
  },
  {
    name: "nanosp",
    label: "Nano S+",
    steps: 5, // <= Define the number of steps for this test case and this device
  },
];

devices.forEach((device) =>
  processTest(device, contractName, testLabel, testDirSuffix, "", signedPlugin, serializedTx, testNetwork)
);