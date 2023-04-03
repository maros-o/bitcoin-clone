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

### Chain
The Chain class is responsible for managing the blockchain. It provides methods to add new transactions to the blockchain, mine new blocks, and retrieve information about the blockchain.

To use the Chain class, you first need to create an instance of it using the get_instance() method. This method ensures that there is only one instance of the Chain class throughout the application.

```bash
Chain& chain = Chain::get_instance();
```

#### Mining
To mine a new block, call the mine() method with the miner's Bitcoin address as the parameter. This method adds a new block to the blockchain with the pending transactions and rewards the miner with the mining reward.

```bash
chain.mine(miner_address);
```
