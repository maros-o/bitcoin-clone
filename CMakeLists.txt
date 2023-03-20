cmake_minimum_required(VERSION 3.8)
project(BITCOIN)

find_package(OpenSSL REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_compile_options(-Wall -Wextra -pedantic)

add_executable(miner src/miner.cpp src/hashlib.cpp include/hashlib.h include/Block.h src/Block.cpp)
add_executable(wallet src/wallet.cpp src/hashlib.cpp include/hashlib.h)

target_link_libraries(miner OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(wallet OpenSSL::SSL OpenSSL::Crypto)