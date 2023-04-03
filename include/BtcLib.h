#pragma once

#include <vector>
#include <string>

class btc {
public:
    using byte = unsigned char;
    using bytes = std::vector<byte>;

    static btc::bytes base58_encode(const btc::bytes& input, bool remove_leading_zeros = true);
    static btc::bytes base58check(const btc::bytes& input, btc::byte version);
    static std::string bytes_to_str(const btc::bytes& vec);
    static std::string bytes_to_hex_str(const btc::bytes& vec);
    static btc::bytes uint64_to_bytes(uint64_t value);

    btc() = delete;
};

const uint8_t MINING_DIFFICULTY = 10;
const uint64_t MINING_REWARD = 100;
const uint16_t MAX_TRANSACTIONS = 10;
const btc::bytes DEFAULT_HASH_VALUE{'3', '7', 'a', '8', 'e', 'e', 'c', '1', 'c', 'e', '1', '9', '6', '8',
                                    '7', 'd', '1', '3', '2', 'f', 'e', '2', '9', '0', '5', '1', 'd', 'c',
                                    'a', '6', '2', '9', 'd', '1', '6', '4', 'e', '2', 'c', '4', '9', '5',
                                    '8', 'b', 'a', '1', '4', '1', 'd', '5', 'f', '4', '1', '3', '3', 'a',
                                    '3', '3', 'f', '0', '6', '8', '8', 'f'};
