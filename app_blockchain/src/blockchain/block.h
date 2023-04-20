#pragma once
#include <iostream>

#include "block.h"
#include "referenceData.h"

namespace blockchain
{
    class Block
    {
    public:
        int nonce;
        std::string preHash;
        blockchain::ReferenceData refData;
        std::string ts;

        Block(std::string previousHash, blockchain::ReferenceData referenceData, std::string timestamp);
    };
}
