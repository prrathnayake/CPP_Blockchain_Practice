#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>

#include "wallet.h"
#include "transtraction.h"
#include "crypto/rsa.h"

blockchain::Wallet::Wallet(std::string userName)
{
    std::map<std::string, std::string> pair = blockchain::CryptoRSA::generateKeyPair();

    name = userName;
    privateKey = pair["privateKey"];
    publicKey = pair["publicKey"];
}

void blockchain::Wallet::createTranstraction(std::string to, float amount)
{
    blockchain::Transtraction transtraction(publicKey, to, amount, blockchain::CryptoRSA::generateSignature(privateKey, (publicKey + to + std::to_string(amount))));
    std::cout << "Transtraction send to the MemPool\n";
}
