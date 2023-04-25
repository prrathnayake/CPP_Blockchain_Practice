#pragma once
#include <iostream>
#include <map>

namespace blockchain
{
    class Transtraction
    {
    public:
        int TxID;
        std::string from;
        std::string to;
        std::string timestamp;
        float amount;
        std::string signature;
        
        Transtraction();
        Transtraction(std::string from, std::string to, float amount, std::string signature);
        std::string toString();
    };
}