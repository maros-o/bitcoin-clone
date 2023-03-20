#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "../include/hashlib.h"
#include "../include/Block.h"

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


int main() {
    std::srand(std::time(nullptr)); // Seed the random number generator
    std::vector<Block> blockchain{Block(1, "Genesis", "0000000000000000000000000000000000000000000000000000000000000000")};

    while(blockchain.size() <= 10) {
        auto block = blockchain.back();
        block.mine();
        block.print();
        blockchain.push_back(Block(block.getIndex() + 1, random_string(), block.getHash()));
    }

    return EXIT_SUCCESS;
}