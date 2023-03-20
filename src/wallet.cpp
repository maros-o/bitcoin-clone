#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <iomanip>

#include "../include/hashlib.h"

std::string random_string() {
    uint8_t length = rand() % 100;

    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    std::string str(length, ' ');

    for (int i = 0; i < length; ++i) {
        str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return str;
}

std::string generate_btc_private_key() {
    // Use a random device to generate a seed for the random number generator
    std::random_device rd;
    std::mt19937_64 eng(rd());

    // Generate a random 256-bit integer
    std::uniform_int_distribution<uint64_t> distr;
    uint64_t key[4];
    for (int i = 0; i < 4; i++) {
        key[i] = distr(eng);
    }

    // Convert the integer to a hex string
    std::ostringstream ss;
    for (int i = 0; i < 4; i++) {
        ss << std::setfill('0') << std::setw(16) << std::hex << key[i];
    }
    return ss.str();
}

int main() {
    std::cout << hashlib::sha256("maros") << std::endl;

    std::cout << hashlib::ripemd160("maros") << std::endl;

    std::cout << generate_btc_private_key() << std::endl;

    return EXIT_SUCCESS;
}