#include <iostream>

#include <blockchain/index.h>

int main()
{
    blockchain::User user("pasan");
    user.createTranstraction("" , 100.45);

    return 0;
}