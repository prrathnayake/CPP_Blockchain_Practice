#include <iostream>

#include <blockchain/index.h>

int main()
{
    blockchain::Wallet wallet("pasan");
    wallet.createTranstraction("" , 100.45);

    return 0;
}