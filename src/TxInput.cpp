#include <iostream>

#include "../include/TxInput.h"

void TxInput::print() const {
    std::cout << " --- TxInput ---" << std::endl;
    std::cout << "txId: " << btc::bytes_to_hex_str(this->txId) << std::endl;
    std::cout << "vout: " << this->vout << std::endl;
    std::cout << "scriptSig: " << btc::bytes_to_hex_str(this->scriptSig) << std::endl;
}
