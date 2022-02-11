#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include "Entity/Entity.h"

class Level
{
    public:
    Level();

    void init(sf::Texture& p_forgroundTexture, sf::Texture& p_backgroundTexture);

    const bool isEntityColliding(const Entity& p_entity) const;
    const bool isSpriteColliding(const sf::Sprite& p_sprite) const;

    void draw(sf::RenderTarget* p_target);

    const sf::FloatRect getGlobalBounds() const;

    private:
    sf::Texture m_foregroundTexture;
    sf::Texture m_backgroundTexture;

    sf::Sprite m_foreground;
    sf::Sprite m_background;
};

#endif // LEVEL_H
