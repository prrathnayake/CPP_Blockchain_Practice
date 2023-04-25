#pragma once
#include <iostream>
#include <map>

#include "block.h"

namespace blockchain
{
    class Miner
    {
    private:
        std::string name;
        std::string privateKey;
        std::string publicKey;

    public:
        std::map<int, blockchain::Transtraction> getPrndingTranstractionFromMemPool();
        void minning();
        void sendBlockToBlockchain(blockchain::Block block);
        bool isValidateSignature(blockchain::Transtraction transtraction);
    };
}