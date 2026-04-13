#ifndef BITCOIN_CHAINPARAMSSEEDS_H
#define BITCOIN_CHAINPARAMSSEEDS_H
/**
 * kapcoin: hardcoded peer-IP fallback list.
 *
 * Empty by design — kapcoin has no public peers yet. Once you have always-on
 * bootstrap nodes, regenerate this file with contrib/seeds/generate-seeds.py
 * pointed at a list of their IPs.
 *
 * Format (when populated): each line is a BIP155 serialized
 * (networkID, addr, port) tuple.
 */
static const uint8_t chainparams_seed_main[] = {};
static const uint8_t chainparams_seed_test[] = {};
#endif // BITCOIN_CHAINPARAMSSEEDS_H
