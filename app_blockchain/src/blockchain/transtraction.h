#pragma once
#include <iostream>
#include <map>

namespace blockchain
{
    class Transtraction
    {
    private:
        std::string changeBy;
        std::string timestamp;
        std::string key;
        std::string value;

    public:
        Transtraction();
        Transtraction(std::string changeBy, std::string key, std::string value);
        std::string toString();
        std::string getKey();
        std::string getValue();
    };
}