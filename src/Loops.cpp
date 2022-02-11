#include "Loops.h"

#include "Game/Credits.h"
#include "Game/Intro.h"
#include "Game/Menu.h"
#include "Levels/Level000.h"
#include "Levels/Level001.h"
#include "Levels/Level002.h"
#include "Util/WindowUtils.h"

void loopGame(Game& p_game)
{
    switch (p_game.data.levelNumber)
    {
        case 0:
        level000(p_game);
        break;

        case 1:
        level001(p_game);
        break;

        case 2:
        level002(p_game);
        break;

        default:
        p_game.pollWindowEvents();
        break;
    }
}

void loopIntro(Game& p_game)
{
    bool loopRunning = true;

    Intro intro;
    intro.init(p_game.resources.fonts["times"], p_game.window);

    while (loopRunning && p_game.window->isOpen() && p_game.data.state == INTRO)
    {
        p_game.pollWindowEvents();

        intro.update(p_game);

        p_game.window->clear(sf::Color(0, 0, 0, 255));
        intro.draw(p_game.window);
        p_game.window->display();
    }
}

void loopMenu(Game& p_game)
{
    bool loopRunning = true;

    Menu menu(p_game.resources.music["giant_disco"], p_game.resources.music["rickroll"]);
    menu.init(p_game, p_game.resources.textures["menu_background"], p_game.resources.fonts["times"]);

    while (loopRunning && p_game.window->isOpen() && p_game.data.state == MENU)
    {
        p_game.pollWindowEvents();

        menu.update(p_game);

        p_game.window->clear();
        menu.draw(p_game.window);
        p_game.window->display();
    }
}

void loopCredits(Game& p_game)
{
    bool loopRunning = true;

    Credits credits;
    credits.init(p_game, p_game.resources.textures["menu_background"], p_game.resources.fonts["times"]);

    while (loopRunning && p_game.window->isOpen() && p_game.data.state == CREDITS)
    {
        p_game.pollWindowEvents();
        
        credits.update();

        p_game.window->clear();
        credits.draw(p_game.window);
        p_game.window->display();
    }
}
