#pragma once

#include "../include/HashLib.h"
#include "../include/Transaction.h"
#include "../include/Block.h"
#include "../include/BtcLib.h"

class Chain {
public:
    static Chain& get_instance() {
        static Chain instance;
        return instance;
    }

    void mine(const btc::bytes miner_address);
    void add_transaction(const Transaction& transaction);

    Chain(const Chain&) = delete;
    Chain& operator=(const Chain&) = delete;

private:
    Chain();
    std::vector<Block> chain;
    std::vector<Transaction> pending_transactions;
    uint64_t mining_reward;
};
