#include <iostream>
#include <vector>
#include <openssl/sha.h>

#include "blockchain.h"
#include "block.h"
#include "transtraction.h"

blockchain::Blockchain::Blockchain()
{
    blockchain::Block genesisBlock;
    hash = mine(genesisBlock);
}

void blockchain::Blockchain::addNewTranstraction(blockchain::Transtraction transtraction)
{
    // if (transtraction.isValidateSignature())
    // {
    //     blockchain::Block block(hash, transtraction, "timestamp");
    //     hash = mine(block);
    // }
    // else
    // {
    //     std::cout << "Transtraction is not valid\n";
    // }
}

void blockchain::Blockchain::addNewWallet(std::string wallet)
{
    wallets.push_back(wallet);
}

void blockchain::Blockchain::printBlockchain()
{
    std::cout << "\nBlockchain\n";
    std::cout << "===========\n\n";
    for (int i = 0; i < blocks.size(); i++)
    {
        std::cout << "Block : " << i << "\n";
        std::cout << blocks[i].toString() << "\n";
    }
}



