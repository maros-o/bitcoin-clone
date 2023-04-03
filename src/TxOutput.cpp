#include <iostream>

#include "../include/TxInput.h"
#include "../include/TxOutput.h"


void TxOutput::print() const {
    std::cout << " --- TxOutput (" << this->index << ") ---" << std::endl;
    std::cout << "amount: " << this->amount << std::endl;
    std::cout << "address: " << this->address << std::endl;
    std::cout << "scriptPubKey: " << btc::bytes_to_hex_str(this->scriptPubKey) << std::endl;
}
