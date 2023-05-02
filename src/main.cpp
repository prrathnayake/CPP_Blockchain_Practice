#include <iostream>

#include "index.h"
#include "wallet.h"

int main()
{
    blockchain::Wallet wallet("pasan");
    wallet.createTranstraction("" , 100.45);

    return 0;
}