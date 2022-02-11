#include <cstdlib>
#include <cstdio>
#include <SFML/Graphics.hpp>

#include "Loops.h"
#include "Util/GameUtils.h"
#include "Util/OsWindowsUtils.h"
#include "Util/Structs.h"
#include "Util/WindowUtils.h"

#include "Game.h"

int main(int argc, char** argv)
{
    Game game;

    srand(time(0));

    bool showConsole = false;

    if (argc > 1)
    {
        printf("Parsing arguments\n");
        for (int i = 1; i < argc; ++i)
        {
            std::string argument = std::string(argv[i]);
            if (argument == "-skipmenu")
            {
                game.data.state = GAME;
            }

            if (argument == "-showconsole")
            {
                showConsole = true;
            }
        }
    }

    displayConsole(showConsole);

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

    return 0;
}
