#pragma once
#include <iostream>
#include <map>

#include "transtraction.h"

namespace blockchain
{
    class User
    {
    private:
        std::string name;
        std::string privateKey;

    public:
        std::string publicKey;
        User(std::string name);
        std::map<std::string, std::string> generateKeyPair();
        void createTranstraction(std::string to, float amount);
        std::string generateSignature(std::string data);
        void sendToMemPool(blockchain::Transtraction transtraction);
    };
}