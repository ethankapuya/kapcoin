# Kapcoin (KAP)

A scrypt proof-of-work cryptocurrency, consisting of a fully functional Layer-1 chain and (hopefully) robust architecture and tooling for network participants.

## About the Coin

| | |
|---|---|
| Algorithm | Scrypt (used by Dogecoin, Litecoin) |
| Block time | 2.5 minutes |
| Block reward | 50 KAP |
| Halving interval | 840,000 blocks |
| Max supply | 84,000,000 KAP |
| Address prefix | `K` (legacy), `kap1` (bech32) |
| Default P2P port | 9555 |
| Default RPC port | 9554 |
| Genesis message | `kapcoin genesis 2026-04-08 - a coin named after me` |

## Download

Pre-built binaries for Linux and macOS are available on the [Releases](../../releases) page.

## Build from source

### Dependencies (macOS)

```sh
brew install autoconf automake berkeley-db@4 boost libevent libtool \
             fmt openssl pkg-config protobuf zeromq
```

### Dependencies (Ubuntu/Debian)

```sh
sudo apt-get install -y build-essential libtool autotools-dev automake \
    pkg-config bsdmainutils python3 libboost-all-dev libevent-dev \
    libssl-dev libdb4.8-dev libdb4.8++-dev libzmq3-dev libfmt-dev
```

### Compile

```sh
./autogen.sh
./configure --with-gui=no --disable-tests --disable-bench
make -j$(nproc)
```

On macOS with Homebrew, you may need to pass extra flags:

```sh
./configure --with-gui=no --disable-tests --disable-bench --without-miniupnpc \
    BDB_LIBS="-L$(brew --prefix berkeley-db@4)/lib -ldb_cxx" \
    BDB_CFLAGS="-I$(brew --prefix berkeley-db@4)/include" \
    --with-boost=$(brew --prefix boost) \
    LDFLAGS="-L$(brew --prefix)/lib" \
    CPPFLAGS="-I$(brew --prefix)/include"
```

Binaries end up in `src/`:
- `litecoind` — the daemon (will be renamed to `kapcoind` in a future release)
- `litecoin-cli` — the RPC client

## Run

### Start the daemon

```sh
./src/litecoind -daemon
```

### Connect to the seed node

Until DNS seeds are set up, connect manually:

```sh
./src/litecoind -daemon -addnode=163.192.54.36:9555
```

Replace `163.192.54.36` with the IP of a known kapcoin node (see the Releases page or project description for the current seed node IP).

### Check status

```sh
./src/litecoin-cli getblockchaininfo
./src/litecoin-cli getpeerinfo
```

## Mine

### Create a wallet and get an address

```sh
./src/litecoin-cli createwallet "mywallet"
./src/litecoin-cli getnewaddress
```

Your address will start with `K`.

### Solo mine (regtest / local testing)

```sh
./src/litecoin-cli generatetoaddress 10 <your-K-address>
```

This instantly mines 10 blocks and sends the 50 KAP reward for each to your address. Only works on regtest.

### Mine on mainnet

Mainnet mining requires an external miner that supports stratum + scrypt. Point any Litecoin-compatible mining software at your node's RPC:

```
stratum+tcp://127.0.0.1:9554
```

Since kapcoin uses the same scrypt algorithm as Litecoin, any Litecoin miner (CPU, GPU, or ASIC) works.

## Network

Kapcoin runs three independent networks:

| Network | P2P port | RPC port | Flag |
|---|---|---|---|
| Mainnet | 9555 | 9554 | (default) |
| Testnet | 19555 | 19554 | `-testnet` |
| Regtest | 19556 | 19557 | `-regtest` |

Data directory: `~/.litecoin/` (will be changed to `~/.kapcoin/` in a future release).

## Project structure

This repo is the Layer-1 chain (path 1). There's also an ERC-20 token version (path 2) in a sibling `token/` directory — see the parent repo for details.

## License

Kapcoin is released under the terms of the MIT license. See [COPYING](COPYING) for more information.

## Credits

Forked from [Litecoin](https://github.com/litecoin-project/litecoin), which is itself forked from [Bitcoin](https://github.com/bitcoin/bitcoin).
