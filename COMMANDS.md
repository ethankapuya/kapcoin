# Kapcoin CLI Command Reference

All commands are run via `kapcoin-cli`. If running from source, prefix with `./src/`:

```sh
./src/kapcoin-cli <command> [arguments]
```

For detailed help on any command:

```sh
./src/kapcoin-cli help <command>
```

## Wallet

| Command | Description |
|---|---|
| `createwallet "name"` | Create a new wallet |
| `loadwallet "name"` | Load an existing wallet |
| `unloadwallet "name"` | Unload a wallet |
| `listwallets` | List all loaded wallets |
| `getwalletinfo` | Wallet status and metadata |
| `getbalance` | Show spendable balance |
| `getbalances` | Show all balances (trusted, untrusted, immature) |
| `getunconfirmedbalance` | Show unconfirmed incoming balance |
| `getnewaddress` | Generate a new receiving address |
| `getrawchangeaddress` | Generate a new change address |
| `listunspent` | Show all spendable outputs |
| `listtransactions` | Show transaction history |
| `gettransaction "txid"` | Get details of a specific transaction |
| `listaddressgroupings` | Show addresses grouped by common ownership |
| `getaddressinfo "address"` | Detailed info about an address |
| `getaddressesbylabel "label"` | List addresses with a given label |
| `setlabel "address" "label"` | Assign a label to an address |
| `listlabels` | List all labels |
| `keypoolrefill` | Refill the key pool |

## Keys and backup

| Command | Description |
|---|---|
| `dumpprivkey "address"` | Export the private key for an address |
| `importprivkey "key"` | Import a private key into the wallet |
| `dumpwallet "filepath"` | Export all wallet keys to a file |
| `importwallet "filepath"` | Import keys from a wallet dump file |
| `backupwallet "filepath"` | Save a full wallet backup |
| `importaddress "address"` | Add a watch-only address |
| `importpubkey "pubkey"` | Add a watch-only public key |
| `sethdseed` | Set or rotate the HD wallet seed |

## Encryption

| Command | Description |
|---|---|
| `encryptwallet "passphrase"` | Encrypt the wallet (irreversible) |
| `walletpassphrase "passphrase" timeout` | Unlock the wallet for `timeout` seconds |
| `walletlock` | Lock the wallet immediately |
| `walletpassphrasechange "old" "new"` | Change the wallet passphrase |

## Sending and receiving

| Command | Description |
|---|---|
| `sendtoaddress "address" amount` | Send KAP to an address |
| `sendmany "" {"addr":amount,...}` | Send to multiple addresses at once |
| `settxfee amount` | Set the default transaction fee |
| `bumpfee "txid"` | Increase fee on an unconfirmed transaction |
| `validateaddress "address"` | Check if an address is valid |
| `signmessage "address" "message"` | Sign a message with your private key |
| `verifymessage "address" "sig" "msg"` | Verify a signed message |
| `getreceivedbyaddress "address"` | Total received by an address |
| `getreceivedbylabel "label"` | Total received by a label |
| `listreceivedbyaddress` | List amounts received by each address |
| `listreceivedbylabel` | List amounts received by each label |
| `listsinceblock "blockhash"` | All transactions since a given block |
| `abandontransaction "txid"` | Mark a conflicting transaction as abandoned |

## Mining

| Command | Description |
|---|---|
| `getmininginfo` | Mining status: hashrate, difficulty, block height |
| `getnetworkhashps` | Estimated network hash rate |
| `generatetoaddress n "address"` | Mine `n` blocks, send rewards to address |
| `generateblock "address" ["txid",...]` | Mine a block with specific transactions |
| `getblocktemplate` | Get a block template for external miners |
| `submitblock "hexdata"` | Submit a mined block to the network |
| `submitheader "hexdata"` | Submit a block header |
| `prioritisetransaction "txid" fee` | Boost a transaction's priority for mining |

## Blockchain

| Command | Description |
|---|---|
| `getblockchaininfo` | Chain overview: height, best hash, difficulty |
| `getblockcount` | Current chain height |
| `getbestblockhash` | Hash of the latest block |
| `getblockhash height` | Get block hash at a given height |
| `getblock "hash"` | Full details of a specific block |
| `getblockheader "hash"` | Block header only |
| `getblockstats height` | Per-block statistics (fees, size, etc.) |
| `getchaintips` | All known chain tips |
| `getchaintxstats` | Transaction rate statistics |
| `getdifficulty` | Current mining difficulty |
| `gettxout "txid" n` | Check a specific unspent transaction output |
| `gettxoutsetinfo` | UTXO set statistics |
| `gettxoutproof ["txid",...]` | Get a Merkle proof for transactions |
| `verifytxoutproof "proof"` | Verify a Merkle proof |
| `getmempoolinfo` | Pending transaction pool status |
| `getrawmempool` | List all pending transaction IDs |
| `getmempoolentry "txid"` | Details of a specific mempool transaction |
| `getmempoolancestors "txid"` | Ancestor transactions in the mempool |
| `getmempooldescendants "txid"` | Descendant transactions in the mempool |
| `verifychain` | Verify the local blockchain database |
| `savemempool` | Save mempool to disk |
| `preciousblock "hash"` | Mark a block as precious (prefer this chain tip) |
| `pruneblockchain height` | Prune blocks up to a given height |

## Raw transactions

| Command | Description |
|---|---|
| `createrawtransaction [inputs] [outputs]` | Create an unsigned raw transaction |
| `decoderawtransaction "hex"` | Decode a raw transaction to JSON |
| `decodescript "hex"` | Decode a script to readable form |
| `fundrawtransaction "hex"` | Add inputs to fund a raw transaction |
| `getrawtransaction "txid"` | Get raw transaction data |
| `sendrawtransaction "hex"` | Broadcast a signed raw transaction |
| `signrawtransactionwithkey "hex" ["key"]` | Sign with provided private keys |
| `signrawtransactionwithwallet "hex"` | Sign with wallet keys |
| `combinerawtransaction ["hex",...]` | Combine partially signed transactions |
| `testmempoolaccept ["hex",...]` | Test if a transaction would be accepted |

## PSBT (Partially Signed Bitcoin Transactions)

| Command | Description |
|---|---|
| `createpsbt [inputs] [outputs]` | Create an unsigned PSBT |
| `decodepsbt "psbt"` | Decode a PSBT to JSON |
| `analyzepsbt "psbt"` | Analyze a PSBT for completeness |
| `combinepsbt ["psbt",...]` | Combine multiple PSBTs |
| `finalizepsbt "psbt"` | Finalize a PSBT into a sendable transaction |
| `joinpsbts ["psbt",...]` | Join multiple PSBTs into one |
| `utxoupdatepsbt "psbt"` | Update PSBT with UTXO data |
| `walletcreatefundedpsbt [inputs] [outputs]` | Create and fund a PSBT from wallet |
| `walletprocesspsbt "psbt"` | Sign a PSBT with wallet keys |

## Network

| Command | Description |
|---|---|
| `getnetworkinfo` | Network stats, version, connections |
| `getpeerinfo` | List all connected peers |
| `getconnectioncount` | Number of active connections |
| `getnettotals` | Total bytes sent and received |
| `getnodeaddresses` | Known node addresses |
| `addnode "ip:port" "add/remove/onetry"` | Manually manage peer connections |
| `getaddednodeinfo` | Info about manually added nodes |
| `disconnectnode "ip:port"` | Disconnect a specific peer |
| `setnetworkactive true/false` | Enable or disable all networking |
| `ping` | Send a ping to all peers |
| `setban "ip" "add/remove"` | Ban or unban a peer |
| `listbanned` | List all banned peers |
| `clearbanned` | Clear the ban list |

## Node control

| Command | Description |
|---|---|
| `stop` | Shut down kapcoind |
| `uptime` | How long the node has been running (seconds) |
| `getmemoryinfo` | Memory usage details |
| `getrpcinfo` | RPC server status |
| `logging ["include"] ["exclude"]` | Get or set log categories |
| `help` | List all commands |
| `help "command"` | Detailed help for a specific command |

## Utility

| Command | Description |
|---|---|
| `createmultisig n ["key",...]` | Create a multisig address |
| `deriveaddresses "descriptor"` | Derive addresses from a descriptor |
| `estimatesmartfee conf_target` | Estimate fee for confirmation in N blocks |
| `getdescriptorinfo "descriptor"` | Analyze an output descriptor |
| `getindexinfo` | Status of optional indexes |
| `signmessagewithprivkey "key" "msg"` | Sign a message with any private key |
