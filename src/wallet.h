#pragma once
#include <iostream>
#include <map>

#include "transtraction.h"

namespace blockchain
{
    class Wallet
    {
    private:
        std::string privateKey;

    public:
        std::string name;
        std::string publicKey;

        Wallet(std::string name);
        void createTranstraction(std::string to, float amount);
    };
}