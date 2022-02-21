#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include "Game.h"

enum TileType
{
    AIR,
    SOLID
};

class Tile
{
    public:
    Tile(sf::Texture& p_tex, sf::IntRect p_rect, TileType p_type);
    ~Tile();

    const bool isOnScreen(Game &p_game) const;
    const bool isOnScreen(sf::View &p_camera) const;

    void setX(float p_x);
    void setY(float p_y);
    void setPos(float p_x, float p_y);
    void setPos(sf::Vector2f p_pos);
    const sf::Vector2f getPos() const;

    void draw(sf::RenderTarget *p_target) const;

    private:
    sf::Vector2f m_pos;
    TileType m_type;

    sf::RectangleShape m_hitbox;
    sf::Sprite m_sprite;
};

#endif // TILE_H