#pragma once
#include <iostream>
#include <vector>

#include "block.h"
#include "transtraction.h"

namespace blockchain
{
    class Block
    {
    private:
        int nonce = 0;
        std::string previousHash = "";
        std::vector<blockchain::Transtraction> transtractions;
        std::string timestamp = "";

    public:
        Block();
        Block(std::string previousHash, std::vector<blockchain::Transtraction> transtractions, std::string timestamp);
        std::string toString();
        int getNonce();
        void setNonce(int nonce);
    };
}
