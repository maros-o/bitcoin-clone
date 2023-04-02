#pragma once

#include <string>
#include <utility>

#include "TxInput.h"
#include "TxOutput.h"

// version and lock time will be ignored for sake of simplicity

struct Transaction {
    btc::bytes txId;
    std::vector<TxInput> inputs;
    std::vector<TxOutput> outputs;
};
