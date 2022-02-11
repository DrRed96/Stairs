#include "Tile.h"

Tile::Tile()
{}

Tile::~Tile()
{}

const bool Tile::isOnScreen(Game &p_game) const
{
    return this->isOnScreen(p_game.camera);
}

const bool Tile::isOnScreen(sf::View &p_camera) const
{
    sf::Vector2f center = p_camera.getCenter(), size = p_camera.getSize();
    return m_hitbox.getGlobalBounds().intersects(sf::FloatRect(center.x-size.x/2, center.y-size.y/2, size.x, size.y));
}

void Tile::draw(sf::RenderTarget *p_target) const
{
    p_target->draw(m_sprite);
}
