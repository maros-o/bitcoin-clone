#include <iostream>

#include "../include/HashLib.h"
#include "../include/Wallet.h"

void test_hash_functions(const btc::bytes& input) {
    std::cout << "--- test_hash_functions ---" << std::endl;
    std::cout << "input string  : " << btc::bytes_to_str(input) << std::endl;

    std::cout << "sha256        : " << btc::bytes_to_hex_str(hashlib::sha256(input)) << std::endl;
    std::cout << "ripemd160     : " << btc::bytes_to_hex_str(hashlib::ripemd160(input)) << std::endl;
    std::cout << "base58_encoded: " << btc::bytes_to_str(btc::base58_encode(input)) << std::endl;
    std::cout << "base58check   : " << btc::bytes_to_str(btc::base58check(input, 0x00)) << std::endl;
}

void test_private_public_key_address(size_t tests) {
    std::cout << "--- test_private_public_key_address ---" << std::endl;
    for (size_t i = 0; i < tests; i++) {
        Wallet wallet{};
        wallet.print();
        std::cout << std::endl;
    }
    // according to https://www.blockonomics.co addresses are valid :)
}

int main() {
    std::vector<std::string> test_words = {"maros", "default", "Hello world"};
    for (const auto& word : test_words) {
        test_hash_functions(btc::bytes(word.begin(), word.end()));
        std::cout << std::endl;
    }

    test_private_public_key_address(10);

    return EXIT_SUCCESS;
}