#ifndef OSWINDOWSUTILS_H
#define OSWINDOWSUTILS_H

#include <SFML/Config.hpp>

#ifdef SFML_SYSTEM_WINDOWS

#include <string>

std::string shellDisplay(const char* p_cmd);

void shell(const char* p_cmd);

void displayConsole(bool p_display = true);

#endif // SFML_SYSTEM_WINDOWS

#endif // OSWINDOWSUTILS_H
