#include <iostream>
#include <vector>

#include "blockchain.h"
#include "block.h"
#include "transtraction.h"
#include "database.h"

void blockchain::Blockchain::addNewDatabase(blockchain::Database database)
{
    databases.push_back(database);
}

void blockchain::Blockchain::addNewTranstraction(blockchain::Transtraction transtraction)
{
    if (blocks.size() == 0)
    {
        blockchain::Transtraction trans("publicKey", "key", "0");
        blockchain::Block bl("preHash", trans, "timestamp");
        blocks.push_back(bl);

        for (int i = 0; i < databases.size(); i++)
        {
            databases[i].addData("key", "0");
        }
    }

    blockchain::Block block("preHash", transtraction, "timestamp");
    blocks.push_back(block);
    for (int i = 0; i < databases.size(); i++)
    {
        databases[i].addData(transtraction.getKey(), transtraction.getValue());
    }
}

void blockchain::Blockchain::printData(blockchain::Database database)
{
    for (int i = 0; i < databases.size(); i++)
    {
        databases[i].printData();
    }
}
