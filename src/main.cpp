#include <iostream>

#include "index.h"
#include "node/wallet.h"

int main()
{
    blockchain::Wallet wallet;
    wallet.createTranstraction("" , 100.45);

    return 0;
}