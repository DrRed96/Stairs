#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include "Game.h"

class Tile
{
    public:
    Tile();
    ~Tile();

    enum TileType
    {
        NONE = 0,
        SOLID,
        AIR
    };

    const bool isOnScreen(Game& p_game) const;
    const bool isOnScreen(sf::View& p_camera) const;

    void draw(sf::RenderTarget* p_target) const;

    private:
    sf::Vector2f m_pos;

    sf::RectangleShape m_hitbox;
    sf::Sprite m_sprite;
};

#endif // TILE_H