#include "StdUtils.h"

std::string concatStringVector(std::vector<std::string> p_strVector, std::string p_seperator)
{
    std::string str;

    for (std::string index : p_strVector)
    {
        str += index;
        if (index != p_strVector[p_strVector.size() - 1])
        {
            str += p_seperator;
        }
    }

    return str;
}
