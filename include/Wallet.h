#pragma once

#include "../include/BtcLib.h"

class Wallet {
public:
    explicit Wallet(std::string name = "test");
    explicit Wallet(std::string name, btc::bytes private_key);

    [[nodiscard]] const btc::bytes& get_private_key() const;
    [[nodiscard]] const btc::bytes& get_public_key() const;
    [[nodiscard]] const btc::bytes& get_address() const;

    static btc::bytes generate_private_key();
    static btc::bytes generate_public_key(const btc::bytes& private_key);
    static btc::bytes generate_address(const btc::bytes& public_key);

    void print() const;

private:
    std::string name;
    btc::bytes private_key;
    btc::bytes public_key;
    btc::byte public_key_version{};
    btc::bytes address;

    void init();
};
