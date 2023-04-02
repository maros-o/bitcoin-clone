#include "../include/BtcLib.h"
#include "../include/HashLib.h"

const char BASE16_ALPHABET[] = "0123456789abcdef";
const char BASE58_ALPHABET[] = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

std::string btc::bytes_to_str(const btc::bytes& vec) {
    std::string result;
    result.reserve(vec.size());
    result.insert(result.begin(), vec.begin(), vec.end());

    return result;
}

std::string btc::bytes_to_hex_str(const btc::bytes& vec) {
    std::string result;
    result.reserve(vec.size() * 2);

    for (const btc::byte& i : vec) {
        result.push_back(BASE16_ALPHABET[i >> 4]);
        result.push_back(BASE16_ALPHABET[i & 0x0f]);
    }
    return result;
}

btc::bytes btc::base58_encode(const btc::bytes& input, bool remove_leading_zeros) {
    btc::bytes data(input.begin(), input.end());

    // count leading zeros
    size_t zeros = 0;
    while (zeros < data.size() && data[zeros] == 0) {
        zeros++;
    }

    // convert bytes to big-endian integer
    btc::bytes result(data.size() * 2);
    for (size_t i = zeros; i < data.size(); i++) {
        int carry = data[i];
        for (btc::byte& j : result) {
            carry += 256 * j;
            j = carry % 58;
            carry /= 58;
        }
    }

    // convert big-endian integer to base58 string
    btc::bytes output(zeros, '1');
    for (int i = (int)(result.size() - 1); i >= 0; i--) {
        output.push_back(BASE58_ALPHABET[result[i]]);
    }

    if (remove_leading_zeros) {
        // remove leading zeros
        while (output.size() > 1 && output[0] == '1') {
            output.erase(output.begin());
        }
    }

    return output;
}

btc::bytes btc::base58check(const btc::bytes& input, btc::byte version) {
    // data = version + input
    btc::bytes data{version};
    data.insert(data.end(), input.begin(), input.end());

    // checksum = sha256(sha256(data))
    btc::bytes hash1 = hashlib::sha256(data);
    btc::bytes checksum = hashlib::sha256(hash1);

    // data += first 4 bytes of checksum
    data.insert(data.end(), checksum.begin(), checksum.begin() + 4);

    return base58_encode(data);
}