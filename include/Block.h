#pragma once

#include <iostream>
#include <string>
#include <cstdint>

const uint8_t DIFFICULTY = 5;
const std::string DEFAULT_HASH_VALUE = "37a8eec1ce19687d132fe29051dca629d164e2c4958ba141d5f4133a33f0688f";

class Block {
public:
    Block(uint64_t index, const std::string& data, const std::string& prevHash);
    void setData(const std::string& data);
    const std::string& getHash() const;
    uint64_t getIndex() const;

    void print();
    void mine();
    static bool checkHash(const std::string& hash);

private:
    uint64_t index;
    uint64_t nonce;
    std::string data;
    std::string prevHash;
    std::string hash;
};