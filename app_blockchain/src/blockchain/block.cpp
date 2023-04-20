#include <iostream>

#include "block.h"

blockchain::Block::Block(std::string previousHash, blockchain::ReferenceData referenceData, std::string timestamp){
    preHash = previousHash;
    refData = referenceData;
    ts = timestamp;
}