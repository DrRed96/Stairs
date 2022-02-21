#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <json.h>
#include <string>

/**
 * Reads a file in binary format
 * @param p_fileName The file to be opened
 * @return The files contents
 */
const std::string openFileBin(std::string p_fileName);

/**
 * Opens a JSON file
 * @param p_fileName The file to be opened
 * @return The file as a Json::Value 
 */
Json::Value openFileJson(std::string p_fileName);

#endif // FILEUTILS_H