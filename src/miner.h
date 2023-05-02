#pragma once
#include <iostream>
#include <map>

#include "block.h"
#include "blockchain.h"

namespace blockchain
{
    class Miner
    {
    private:
        std::string privateKey;

    public:
        std::string name;
        std::string publicKey;
        blockchain::Blockchain blockchain;

        void onTranstractionsFromMempool();
        std::string mine(blockchain::Block block);
        std::string getHash(std::string data);
        bool isValidateSignature(blockchain::Transtraction transtraction);
        void sendBlockToBlockchain(blockchain::Block block);
    };
}