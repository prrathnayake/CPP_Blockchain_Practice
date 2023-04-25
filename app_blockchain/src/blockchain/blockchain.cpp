#include <iostream>
#include <vector>
#include <openssl/sha.h>

#include "blockchain.h"
#include "block.h"
#include "transtraction.h"

blockchain::Blockchain::Blockchain()
{
    // blockchain::Transtraction trans("genesis", 100);
    // blockchain::Block bl("preHash", trans, "timestamp");
    // hash = mine(bl);
}

void blockchain::Blockchain::addNewTranstraction(blockchain::Transtraction transtraction)
{
    // if (transtraction.isValidateSignature())
    // {
    //     blockchain::Block block(hash, transtraction, "timestamp");
    //     hash = mine(block);
    // }
    // else
    // {
    //     std::cout << "Transtraction is not valid\n";
    // }
}

void blockchain::Blockchain::printBlockchain()
{
    std::cout << "\nBlockchain\n";
    std::cout << "===========\n\n";
    for (int i = 0; i < blocks.size(); i++)
    {
        std::cout << "Block : " << i << "\n";
        std::cout << blocks[i].toString() << "\n";
    }
}

std::string blockchain::Blockchain::getHash(std::string data)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char *>(data.c_str()), data.size(), hash);

    // Convert the hash to a hexadecimal string
    std::string hex_hash;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        char hex_byte[3];
        std::sprintf(hex_byte, "%02x", hash[i]);
        hex_hash += hex_byte;
    }
    // Print the hash
    return hex_hash;
}

std::string blockchain::Blockchain::mine(blockchain::Block block)
{
    std::cout << "mining.......\n";
    std::string hash = getHash(block.toStringWithTranstraction());

    bool loop = true;
    while (loop)
    {
        if (hash.rfind("0000", 0) == 0)
        {
            loop = false;
            blocks.push_back(block);
            return hash;
        }
        else
        {
            block.setNonce(block.getNonce() + 1);
            hash = getHash(block.toStringWithTranstraction());
        }
    }
}
