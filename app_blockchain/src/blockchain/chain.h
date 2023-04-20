#pragma once
#include <iostream>
#include <vector>

#include "chain.h"
#include "block.h"

namespace blockchain
{
    class Chain
    {
    public:
        std::vector<blockchain::Block> blocks;

        Chain();
    };
}