#pragma once

#include <cstdint>

#include "BtcLib.h"

// TODO: implement

struct TxOutput {
    // index of the output being spent
    uint32_t index;

    // amount of the output in satoshis
    uint64_t amount;

    std::string address;

    btc::bytes scriptPubKey;

    void print() const;
};