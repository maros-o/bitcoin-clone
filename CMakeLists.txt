cmake_minimum_required(VERSION 3.8)
project(Bitcoin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_compile_options(-Wall -Wextra -pedantic -lsecp256k1)

find_package(OpenSSL REQUIRED)

find_library(SECP256K1_LIBRARY secp256k1)
if(NOT SECP256K1_LIBRARY)
    message(FATAL_ERROR "secp256k1 library not found")
endif()

add_executable(main src/main.cpp src/HashLib.cpp src/Wallet.cpp src/Block.cpp src/BtcLib.cpp src/Transaction.cpp src/TxInput.cpp src/TxOutput.cpp src/Chain.cpp)

target_link_libraries(main OpenSSL::SSL ${SECP256K1_LIBRARY})
