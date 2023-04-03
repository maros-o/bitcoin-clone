#pragma once

#include "BtcLib.h"

// TODO: implement

struct TxInput {
    // transaction id of the output being spent
    btc::bytes txId;

    // index of the output being spent
    uint32_t vout;

    // scriptSig
    btc::bytes scriptSig;

    void print() const;
};