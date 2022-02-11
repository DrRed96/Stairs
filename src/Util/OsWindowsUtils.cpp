#include "OsWindowsUtils.h"

#include <SFML/Config.hpp>

#ifdef SFML_SYSTEM_WINDOWS

#include <cstdio>
#include <cstdlib>
#include <windows.h>

std::string shellDisplay(const char* p_cmd)
{
    FILE *fp;
    char path[1035];

    std::string returnStr = "";

    fp = popen(p_cmd, "r");
    if (fp == NULL) {
        return "NULL";
    }

    while (fgets(path, sizeof(path), fp) != NULL) {
        returnStr += path;
    }

    pclose(fp);
    return path;
}

void shell(const char* p_cmd)
{
    system(p_cmd);
}

void displayConsole(bool p_display)
{
    if (p_display)
    {
        ShowWindow(GetConsoleWindow(), 5);
    }
    else
    {
        ShowWindow(GetConsoleWindow(), 0);
    }
}

#endif // SFML_SYSTEM_WINDOWS
