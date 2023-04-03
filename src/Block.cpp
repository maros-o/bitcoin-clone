#include <utility>

#include "../include/Block.h"
#include "../include/HashLib.h"


Block::Block(uint64_t index, btc::bytes prev_hash) : index(index), nonce(0), prev_hash(std::move(prev_hash)), hash(DEFAULT_HASH_VALUE) {}

uint64_t Block::get_index() const {
    return this->index;
}

const btc::bytes &Block::get_hash() const {
    return this->hash;
}

bool Block::try_solve(uint64_t try_nonce, const btc::bytes& miner_address) {
    btc::bytes data{this->get_hash_data()};

    // add nonce
    btc::bytes nonce_bytes = btc::uint64_to_bytes(try_nonce);
    data.insert(data.end(), nonce_bytes.begin(), nonce_bytes.end());

    btc::bytes try_hash = hashlib::sha256(data);

    if (is_hash_valid(try_hash)) {
        this->nonce = try_nonce;
        this->hash = try_hash;
        // TODO: create coinbase transaction for miner

        return true;
    }
    return false;
}

bool Block::is_hash_valid(const btc::bytes& hash) {
    // Calculate the number of bytes required to meet the difficulty level.
    uint8_t bytes = (MINING_DIFFICULTY + 7) / 8;
    // Check that the required number of bytes are all zero.
    for (int i = 0; i < bytes; ++i) {
        if (hash[i] != 0) {
            return false;
        }
    }
    // Check that the remaining bits are zero.
    uint8_t mask = (1 << (8 - (MINING_DIFFICULTY % 8))) - 1;
    if ((hash[bytes] & mask) != 0) {
        return false;
    }
    return true;
}


void Block::print() const {
    std::cout << " --- Block #" << this->index << " ---" << std::endl;
    std::cout << "nonce: " << this->nonce << std::endl;
    for (const auto& transaction : this->transactions) {
        //transaction.print();
    }
    std::cout << "prevHash: " << btc::bytes_to_hex_str(this->prev_hash) << std::endl;
    if (is_hash_valid(this->hash)) {
        std::cout << "hash (✓): " << btc::bytes_to_hex_str(this->hash) << std::endl;
    } else {
        std::cout << "hash (x): " << btc::bytes_to_hex_str(this->hash) << std::endl;
    }
    std::cout << "\n";
}

bool Block::add_transaction(const Transaction &transaction) {
    if (this->transactions.size() >= MAX_TRANSACTIONS) {
        return false;
    }
    this->transactions.push_back(transaction);
    return true;
}

btc::bytes Block::get_hash_data() const {
    btc::bytes hash_data{8 + 32};

    // add index
    btc::bytes index_bytes = btc::uint64_to_bytes(this->index);

    // add prev hash
    hash_data.insert(hash_data.end(), this->prev_hash.begin(), this->prev_hash.end());

    // TODO: add transactions data

    return hash_data;
}
