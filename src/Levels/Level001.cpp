#include "Level001.h"

#include "Entity/Bob.h"
#include "Entity/Player.h"
#include "Util/WindowUtils.h"

void level001(Game& p_game)
{
    bool loopRunning = true;
    Player player(1.f, 16.f, 1.5f, 0.8f, &p_game.resources.sounds["jump"].sound);
    player.init(p_game.resources.textures["sample_player"], p_game.resources.textures["sample_player"]);
    player.setPos(sf::Vector2f(p_game.window->getSize().x/2, 100));

    Bob bob(1.f, 1.f, 0.8f);
    bob.init(p_game.resources.textures["bob"], p_game.resources.textures["bob"]);
    bob.setPos(sf::Vector2f(p_game.window->getSize().x-60, 100));

    Level level;
    level.init(p_game.resources.textures["lvl_1_fg"], p_game.resources.textures["empty"]);

    p_game.camera.setCenter(sf::Vector2f(p_game.window->getSize().x/2, p_game.window->getSize().y/2));
    
    while (loopRunning && p_game.window->isOpen() && p_game.data.state == GAME && p_game.data.levelNumber == 1)
    {
        p_game.pollWindowEvents();

        player.update(level, p_game.input);
        setCameraPositionRelativeToSpriteAndLevel(p_game, player.getHitbox(), level);
        bob.update(level, player);

        printf("%d\n", bob.isOnScreen(p_game));

        p_game.window->clear(sf::Color(0xDDFFFFFF));
        level.draw(p_game.window);
        player.draw(p_game.window, p_game.camera);
        bob.draw(p_game.window, p_game.camera);
        p_game.window->display();
    }
}