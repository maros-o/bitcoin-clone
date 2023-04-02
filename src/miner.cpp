#include <vector>
#include <cstdlib>
#include <ctime>

#include "../include/Block.h"

int main() {
    std::srand(std::time(nullptr)); // Seed the random number generator
    std::vector<Block> blockchain{Block(1, "Genesis", "0000000000000000000000000000000000000000000000000000000000000000")};

    while(blockchain.size() <= 10) {
        auto block = blockchain.back();
        block.mine();
        block.print();
        blockchain.push_back(Block(block.getIndex() + 1, "random", block.getHash()));
    }

    return EXIT_SUCCESS;
}