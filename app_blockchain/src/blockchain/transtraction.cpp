#include <iostream>
#include "transtraction.h"

blockchain::Transtraction::Transtraction()
{
}

blockchain::Transtraction::Transtraction(std::string c, std::string k, std::string v)
{
    changeBy = c;
    key = k;
    value = v;
}

std::string blockchain::Transtraction::toString()
{
    std::string str = "ChangeBy : " + changeBy + "\n" + "Key : " + key + "\n" + "Value : " + "\n";
    return str;
}

std::string blockchain::Transtraction::getKey()
{
    return key;
}

std::string blockchain::Transtraction::getValue()
{
    return value;
}