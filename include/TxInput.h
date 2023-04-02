#pragma once

#include <string>
#include <cstdint>

#include "BtcLib.h"
#include "Transaction.h"

struct TxInput {
    // transaction id of the output being spent
    btc::bytes txId;

    // index of the output being spent
    uint32_t vout;

    // scriptSig
    btc::bytes scriptSig;
};