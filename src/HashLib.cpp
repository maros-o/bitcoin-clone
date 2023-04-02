#include <algorithm>
#include <openssl/sha.h>
#include <openssl/ripemd.h>

#include "../include/HashLib.h"

btc::bytes hashlib::sha256(const btc::bytes& input) {
    btc::byte hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.data(), input.size());
    SHA256_Final(hash, &sha256);

    return {hash, hash + SHA256_DIGEST_LENGTH};
}

btc::bytes hashlib::ripemd160(const btc::bytes& input) {
    btc::byte hash[RIPEMD160_DIGEST_LENGTH];
    RIPEMD160_CTX ripemd160;
    RIPEMD160_Init(&ripemd160);
    RIPEMD160_Update(&ripemd160, input.data(), input.size());
    RIPEMD160_Final(hash, &ripemd160);

    return {hash, hash + RIPEMD160_DIGEST_LENGTH};
}