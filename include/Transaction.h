#pragma once

#include <string>
#include <utility>

#include "TxInput.h"
#include "TxOutput.h"

// TODO: implement

struct Transaction {
    btc::bytes txId;
    std::vector<TxInput> inputs;
    std::vector<TxOutput> outputs;
    // version and lock time will be ignored for sake of simplicity

    void print() const;
};
