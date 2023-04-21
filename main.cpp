#include <iostream>

#include <blockchain/index.h>

int main()
{
    blockchain::Database database1;
    blockchain::Database database2;
    blockchain::Database database3;

    blockchain::Blockchain blockchain;
    blockchain.addNewDatabase(database1);
    // blockchain.addNewDatabase(database2);
    // blockchain.addNewDatabase(database3);

    blockchain::Transtraction transtraction1("publicKey", "key1", "10");
    blockchain.addNewTranstraction(transtraction1);

    blockchain::Transtraction transtraction2("publicKey", "key2", "20");
    blockchain.addNewTranstraction(transtraction2);

    blockchain::Transtraction transtraction3("publicKey", "key3", "30");
    blockchain.addNewTranstraction(transtraction3);

    database1.printData();

    return 0;
}