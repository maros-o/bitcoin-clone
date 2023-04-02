#pragma once

#include <string>
#include <cstdint>

#include "BtcLib.h"
#include "Transaction.h"


class TxOutput {
private:
    // index of the output being spent
    uint32_t index;

    // amount of the output in satoshis
    uint64_t amount;

    std::string address;

    btc::bytes scriptPubKey;
};