#pragma once
#include <iostream>
#include <vector>

#include "block/block.h"
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

    public:
        Blockchain();
        void addNewTranstraction(blockchain::Transtraction transtraction);
        void addNewWallet(std::string wallet);
        void printBlockchain();
    };
}