#pragma once
#include <iostream>
#include <map>

#include "transtraction.h"
#include "blockchain.h"

namespace blockchain
{
    class Wallet
    {
    private:
        std::string privateKey;

    public:
        std::string name;
        std::string publicKey;
        blockchain::Blockchain blockchain;

        Wallet(std::string name);
        std::map<std::string, std::string> generateKeyPair();
        void createTranstraction(std::string to, float amount);
        std::string generateSignature(std::string data);
        void sendToMemPool(blockchain::Transtraction transtraction);
    };
}