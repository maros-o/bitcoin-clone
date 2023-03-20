#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>
#include <openssl/ripemd.h>
#include <cstdint>


class hashlib {
public:
    static std::string sha256(const std::string& str);
    static std::string ripemd160(const std::string& str);

    hashlib() = delete;
    hashlib(const hashlib&) = delete;
    hashlib(hashlib&&) = delete;
    ~hashlib() = delete;
    hashlib& operator=(const hashlib&) = delete;
    hashlib& operator=(hashlib&&) = delete;
};
