#include "WindowUtils.h"

void setCameraPositionRelativeToSprite(Game& game, const sf::Sprite& p_sprite)
{
    game.camera.setCenter(sf::Vector2f(p_sprite.getPosition().x, p_sprite.getPosition().y));
    game.window->setView(game.camera);
}

void setCameraPositionRelativeToSpriteAndLevel(Game& game, const sf::Sprite& p_sprite, const Level& p_level)
{
    game.camera.setCenter(sf::Vector2f(p_sprite.getPosition().x, p_sprite.getPosition().y));

    if (game.camera.getCenter().x < p_level.getGlobalBounds().left + game.camera.getSize().x/2)
    {
        game.camera.setCenter(sf::Vector2f(p_level.getGlobalBounds().left + game.camera.getSize().x/2, game.camera.getCenter().y));
    }

    if (game.camera.getCenter().x > p_level.getGlobalBounds().left + p_level.getGlobalBounds().width - game.camera.getSize().x/2)
    {
        game.camera.setCenter(sf::Vector2f(p_level.getGlobalBounds().left + p_level.getGlobalBounds().width - game.camera.getSize().x/2, game.camera.getCenter().y));
    }

    if (game.camera.getCenter().y < p_level.getGlobalBounds().top + game.camera.getSize().y/2)
    {
        game.camera.setCenter(sf::Vector2f(game.camera.getCenter().x, p_level.getGlobalBounds().top + game.camera.getSize().y/2));
    }

    if (game.camera.getCenter().y > p_level.getGlobalBounds().top + p_level.getGlobalBounds().height - game.camera.getSize().y/2)
    {
        game.camera.setCenter(sf::Vector2f(game.camera.getCenter().x, p_level.getGlobalBounds().top + p_level.getGlobalBounds().height - game.camera.getSize().y/2));
    }

    game.window->setView(game.camera);
}
