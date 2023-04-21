#include <iostream>

#include "block.h"

blockchain::Block::Block(std::string previousHash, blockchain::Transtraction transtraction, std::string timestamp)
{
    preHash = previousHash;
    trans = transtraction;
    ts = timestamp;
}

void blockchain::Block::generateHash() {}