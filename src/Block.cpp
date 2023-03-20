#include "../include/Block.h"
#include "../include/hashlib.h"


Block::Block(uint64_t index, const std::string &data, const std::string& prevHash) : index(index), data(data), nonce(0), prevHash(prevHash), hash(DEFAULT_HASH_VALUE) {}

void Block::setData(const std::string &data) {
    this->data = data;
}

uint64_t Block::getIndex() const {
    return this->index;
}

const std::string& Block::getHash() const {
    return this->hash;
}

bool Block::checkHash(const std::string& hash) {
    for (uint8_t i = 0; i < DIFFICULTY; ++i) {
        if (hash[i] != '0') {
            return false;
        }
    }
    return true;
}

void Block::print() {
    std::cout << "Block #" << index << std::endl;
    std::cout << " data: " << data << std::endl;
    std::cout << " nonce: " << nonce << std::endl;
    std::cout << " prevHash: " << prevHash << std::endl;
    if (checkHash(this->hash)) {
        std::cout << " hash (✓): " << hash << std::endl;
    } else {
        std::cout << " hash (x): " << hash << std::endl;
    }
}

void Block::mine() {
    std::cout << "Block #" << this->index << " mining..." << std::endl;

    const std::string hash_data_base = std::to_string(this->index) + this->prevHash + this->data;

    while(true) {
        const std::string hash_data = hash_data_base + std::to_string(this->nonce);
        this->hash = hashlib::sha256(hash_data);

        if (checkHash(this->hash)) {
            std::cout << "Block #" << this->index << " mined." << std::endl;
            break;
        }

        this->nonce++;
    }
}