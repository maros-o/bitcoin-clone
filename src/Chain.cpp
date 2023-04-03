#include "../include/Chain.h"

Chain::Chain() {
    this->chain.emplace_back(Block(1, btc::bytes(32, 0)));
}

void Chain::add_transaction(const Transaction &transaction) {
    this->pending_transactions.push_back(transaction);
}

void Chain::mine(const btc::bytes miner_address) {
    while(true) {
        uint64_t nonce = 0;
        Block* current_block = &this->chain[this->chain.size()-1];
        std::cout << "Block #" << current_block->get_index() << " mining... (difficulty: " << (int)MINING_DIFFICULTY << " zero bits)" << std::endl;
        while(true) {
            if (current_block->try_solve(nonce, miner_address)) {
                std::cout << "Block #" << current_block->get_index() << " mined." << std::endl;
                current_block->print();
                break;
            }
            nonce++;
        }
        this->chain.emplace_back(current_block->get_index()+1, current_block->get_hash());
    }
}
