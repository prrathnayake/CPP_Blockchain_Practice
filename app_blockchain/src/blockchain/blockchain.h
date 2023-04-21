#pragma once
#include <iostream>
#include <vector>

#include "block.h"
#include "database.h"

namespace blockchain
{
    class Blockchain
    {
    private:
        int index = 1;
        std::vector<blockchain::Block> blocks;
        std::vector<blockchain::Database> databases;

    public:
        void addNewDatabase(blockchain::Database database);
        void addNewTranstraction(blockchain::Transtraction transtraction);
    };
}