#include <iostream>

#include <blockchain/index.h>

int main()
{
    blockchain::User user("pasan");
    std::string publicKey = user.getPublicKey();
    std::string privateKey = user.getPrivateKey();

    blockchain::Blockchain blockchain;

    blockchain::Transtraction transtraction1(privateKey, publicKey, "key1", "10");
    blockchain.addNewTranstraction(transtraction1);

    blockchain::Transtraction transtraction2(privateKey, publicKey, "key2", "20");
    blockchain.addNewTranstraction(transtraction2);

    blockchain::Transtraction transtraction3(privateKey, publicKey, "key3", "30");
    blockchain.addNewTranstraction(transtraction3);

    blockchain.printBlockchain();

    return 0;
}