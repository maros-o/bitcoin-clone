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

    btc() = delete;
};
