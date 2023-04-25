#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>

#include "user.h"
#include "transtraction.h"

blockchain::User::User(std::string userName)
{
    std::map<std::string, std::string> pair = generateKeyPair();

    name = userName;
    privateKey = pair["privateKey"];
    publicKey = pair["publicKey"];
}

std::map<std::string, std::string> blockchain::User::generateKeyPair()
{
    std::map<std::string, std::string> pair;

    // Generate a 2048-bit RSA key pair
    RSA *rsa = RSA_generate_key(2048, RSA_F4, nullptr, nullptr);

    // Write the private key to a memory buffer
    BIO *priv_bio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(priv_bio, rsa, nullptr, nullptr, 0, nullptr, nullptr);

    // Read the private key from the memory buffer
    char *priv_key;
    long priv_key_len = BIO_get_mem_data(priv_bio, &priv_key);
    std::string private_key(priv_key, priv_key_len);

    // Write the public key to a memory buffer
    BIO *pub_bio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(pub_bio, rsa);

    // Read the public key from the memory buffer
    char *pub_key;
    long pub_key_len = BIO_get_mem_data(pub_bio, &pub_key);
    std::string public_key(pub_key, pub_key_len);

    // Free memory
    RSA_free(rsa);
    BIO_free_all(priv_bio);
    BIO_free_all(pub_bio);

    pair["privateKey"] = private_key;
    pair["publicKey"] = public_key;

    return pair;
}

std::string blockchain::User::generateSignature(std::string data)
{
    RSA *rsa = RSA_new();
    BIO *bio = BIO_new_mem_buf(privateKey.c_str(), -1);
    rsa = PEM_read_bio_RSAPrivateKey(bio, &rsa, nullptr, nullptr);
    BIO_free(bio);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char *>(data.c_str()), data.size(), hash);

    unsigned char signature_buf[RSA_size(rsa)];
    unsigned int signature_len;
    if (!RSA_sign(NID_sha256, hash, SHA256_DIGEST_LENGTH, signature_buf, &signature_len, rsa))
    {
        std::cerr << "Error: could not create signature" << std::endl;
        RSA_free(rsa);
    }

    std::string signature = std::string(reinterpret_cast<const char *>(signature_buf), signature_len);
    RSA_free(rsa);

    return signature;
}

void blockchain::User::createTranstraction(std::string to, float amount)
{
    blockchain::Transtraction transtraction(publicKey, to, amount, generateSignature(publicKey + to + std::to_string(amount)));
    sendToMemPool(transtraction);
}

void blockchain::User::sendToMemPool(blockchain::Transtraction transtraction)
{
    std::cout << "Transtraction send to the MemPool\n";
}