#include "FileUtils.h"

#include <fstream>

const std::string openFileBin(std::string p_fileName)
{
    std::string line;
    std::string contents;
    std::ifstream file(p_fileName, std::ifstream::binary);
    while (std::getline(file, line))
    {
        contents += line;
        contents += "\n";
    }
    file.close();
    return contents;
}

Json::Value openFileJson(std::string p_fileName)
{
    Json::Value root;
    std::ifstream file(p_fileName, std::ifstream::binary);
    file >> root;
    file.close();
    return root;
}
