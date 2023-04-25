#include <iostream>
#include <map>

#include "transtraction.h"
#include "memPool.h"

void blockchain::MemPool::addTranstractionToMemPool(blockchain::Transtraction transtraction){
    transtractions[transtraction.TxID] = transtraction;
}

void blockchain::MemPool::removeTranstractionFromMemPool(int TxID){
    transtractions.erase(TxID);
}