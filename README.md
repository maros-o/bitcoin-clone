# Bitcoin Clone in C++
This project is a simple implementation of Bitcoin in C++. It currently includes classes for a Wallet, Transaction, TxInput, TxOutput, and Block.

## Installation
You will need the following libraries to run this project:

libssl-dev

libsecp256k1-dev

You can install these libraries on Ubuntu using the following commands:
```bash
sudo apt-get install libssl-dev
sudo apt install libsecp256k1-dev
```

## Usage (current)
### Wallet
To create a wallet, you can use the Wallet class. The Wallet class has two constructors, one that takes a std::string for the wallet name and another that takes a std::string for the wallet name and a btc::bytes object for the private key.

You can generate a private key, public key, and Bitcoin address using the generate_private_key(), generate_public_key(), and generate_address() static methods.

Here is an example of creating and printing a wallet:
```bash
Wallet myWallet("My Wallet");
myWallet.print();
```

