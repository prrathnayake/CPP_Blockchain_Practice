#pragma once
#include <iostream>
#include <vector>

#include "block.h"
#include "wallet.h"
#include "memPool.h"

namespace blockchain
{
    class Blockchain
    {
    private:
        std::string hash;
        unsigned int blockCount;
        std::vector<blockchain::Block> blocks;
        std::vector<std::string> wallets;
        blockchain::MemPool memPool;

    public:
        void addNewTranstraction(blockchain::Transtraction transtraction);
        void addNewWallet(std::string wallet);
        void printBlockchain();
        
    };
}