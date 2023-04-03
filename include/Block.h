#pragma once

#include <iostream>
#include <string>
#include <cstdint>

#include "BtcLib.h"
#include "Transaction.h"

class Block {
public:
    Block(uint64_t index, btc::bytes  prevHash);
    [[nodiscard]] const btc::bytes& get_hash() const;
    [[nodiscard]] uint64_t get_index() const;
    bool add_transaction(const Transaction& transaction);

    bool try_solve(uint64_t try_nonce, const btc::bytes& miner_address);
    [[nodiscard]] btc::bytes get_hash_data() const;
    void print() const;

    static bool is_hash_valid(const btc::bytes& hash);

private:
    uint64_t index;
    uint64_t nonce;

    std::vector<Transaction> transactions;

    btc::bytes prev_hash;
    btc::bytes hash;
};