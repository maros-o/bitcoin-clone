#include <iostream>

#include "../include/Transaction.h"

void Transaction::print() const {
    std::cout << " --- Transaction ---" << std::endl;
    std::cout << "txId: " << btc::bytes_to_hex_str(txId) << std::endl;
    for (const auto& input : inputs) {
        input.print();
    }
    for (const auto& output : outputs) {
        output.print();
    }
}