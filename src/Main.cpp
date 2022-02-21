#include <cstdlib>
#include <cstdio>
#include <SFML/Graphics.hpp>

#include "Logger.h"
#include "Game.h"
#include "Loops.h"
#include "Util/GameUtils.h"
#include "Util/OsWindowsUtils.h"
#include "Util/Structs.h"
#include "Util/WindowUtils.h"

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg = std::string(argv[i]);

        if (arg == "--debug" || arg == "-d")
        {
            Logger::debugMode = true;
        }

    }

    if (!Logger::debugMode)
    {
        displayConsole(false);
    }
    else
    {
        Logger::debug("Debug is enabled", __FILE__, __LINE__);
    }

    srand(time(NULL));
    Game game;

    while (game.window->isOpen())
    {
        switch (game.data.state)
        {
            case NONE:
            game.pollWindowEvents();
            break;

            case INTRO:
            loopIntro(game);
            break;

            case MENU:
            loopMenu(game);
            break;

            case GAME:
            loopGame(game);
            break;

            case CREDITS:
            break;
        }
    }

    Logger::saveLogs();
    return 0;
}
