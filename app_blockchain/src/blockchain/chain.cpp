#include <iostream>
#include <vector>

#include "chain.h"
#include "block.h"

blockchain::Chain::Chain()
{
    blockchain::ReferenceData rfData;
    blockchain::Block block("", rfData, "");
    blocks.push_back(block);
}