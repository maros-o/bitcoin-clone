#include <iostream>
#include <utility>
#include <openssl/ec.h>
#include <random>
#include <secp256k1.h>

#include "../include/Wallet.h"
#include "../include/HashLib.h"

Wallet::Wallet(std::string name) : name(std::move(name)), private_key(Wallet::generate_private_key()) {
    this->init();
}

Wallet::Wallet(std::string name, btc::bytes private_key) : name(std::move(name)), private_key(std::move(private_key)) {
    this->init();
}

const btc::bytes &Wallet::get_private_key() const {
    return this->private_key;
}

const btc::bytes &Wallet::get_public_key() const {
    return this->public_key;
}

const btc::bytes &Wallet::get_address() const {
    return this->address;
}

void Wallet::print() {
    std::cout << " --- Wallet (" << this->name << ") --- " << std::endl;
    std::cout << "private key: " << btc::bytes_to_hex_str(this->private_key) << std::endl;
    std::cout << "pub version: 0x0" << (int)this->public_key_version << std::endl;
    std::cout << "public key : " << btc::bytes_to_hex_str(this->public_key) << std::endl;
    std::cout << "address    : " << btc::bytes_to_str(this->address) << std::endl << std::endl;
}

btc::bytes Wallet::generate_private_key() {
    // create random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned long long> dis(0, UINT64_MAX);

    // generate private key
    btc::bytes private_key(32);
    for (int i = 0; i < 4; i++) {
        unsigned long long random_num = dis(gen);
        for (int j = 0; j < 8; j++) {
            private_key[i * 8 + j] = (random_num >> (j * 8)) & 0xFF;
        }
    }
    return private_key;
}

btc::bytes Wallet::generate_public_key(const btc::bytes &private_key) {
    // first byte is version
    btc::bytes public_key(33);
    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

    // create public key
    secp256k1_pubkey pubkey;
    if (!secp256k1_ec_pubkey_create(ctx, &pubkey, private_key.data())) {
        return public_key;
    }

    // serialize public key
    size_t pub_key_len = public_key.size();
    if (!secp256k1_ec_pubkey_serialize(ctx, public_key.data(), &pub_key_len, &pubkey, SECP256K1_EC_COMPRESSED)) {
        public_key.clear();
        return public_key;
    }

    secp256k1_context_destroy(ctx);

    return public_key;
}

btc::bytes Wallet::generate_address(const btc::bytes &public_key) {
    // add prefix '1'
    btc::bytes address{'1'};

    // double hash
    btc::bytes hash = hashlib::sha256(public_key);
    btc::bytes hash2 = hashlib::ripemd160(hash);

    // add base58check of double hash
    btc::bytes base58check = btc::base58check(hash2, 0x00);
    address.insert(address.end(), base58check.begin(), base58check.end());

    return address;
}

void Wallet::init() {
    this->public_key = Wallet::generate_public_key(this->private_key);
    this->public_key_version = this->public_key[0];
    this->public_key.erase(public_key.begin());
    this->address = Wallet::generate_address(this->public_key);
}