#pragma once
#include <iostream>
#include <vector>

#include "block.h"
#include "memPool.h"

namespace blockchain
{
    class Blockchain
    {
    private:
        std::string hash;
        std::vector<blockchain::Block> blocks;
        blockchain::MemPool memPool;

    public:
        Blockchain();
        void addNewTranstraction(blockchain::Transtraction transtraction);
        void printBlockchain();
        std::string getHash(std::string data);
        std::string mine(blockchain::Block block);
    };
}