#include "../include/hashlib.h"

const std::string hash_to_string(const unsigned char* hash, const uint8_t length) {
    const char hex_chars[] = "0123456789abcdef";
    std::string result;
    result.reserve(length * 2);

    for (uint8_t i = 0; i < length; ++i) {
        result += hex_chars[(hash[i] >> 4) & 0xf];
        result += hex_chars[hash[i] & 0xf];
    }

    return result;
}

std::string hashlib::sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    return hash_to_string(hash, SHA256_DIGEST_LENGTH);
}

std::string hashlib::ripemd160(const std::string& str) {
    unsigned char hash[RIPEMD160_DIGEST_LENGTH];
    RIPEMD160_CTX ripemd160;
    RIPEMD160_Init(&ripemd160);
    RIPEMD160_Update(&ripemd160, str.c_str(), str.size());
    RIPEMD160_Final(hash, &ripemd160);

    return hash_to_string(hash, RIPEMD160_DIGEST_LENGTH);
}