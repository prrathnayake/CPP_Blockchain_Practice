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
        void onTranstractionsFromMempool();
        std::string mine(blockchain::Block block);
        std::string getHash(std::string data);
        bool isValidateSignature(blockchain::Transtraction transtraction);
                void sendBlockToBlockchain(blockchain::Block block);
    };
}