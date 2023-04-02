#pragma once

#include <vector>
#include <string>
#include "BtcLib.h"

class hashlib {
public:
    static btc::bytes sha256(const btc::bytes& input);
    static btc::bytes ripemd160(const btc::bytes& input);

    hashlib() = delete;
};
