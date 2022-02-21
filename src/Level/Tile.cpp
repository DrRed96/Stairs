#include "Tile.h"

Tile::Tile(sf::Texture &p_tex, sf::IntRect p_rect, TileType p_type)
    : m_type(p_type)
{
    this->m_sprite.setTexture(p_tex);
    this->m_sprite.setTextureRect(p_rect);
}

Tile::~Tile()
{
}

const bool Tile::isOnScreen(Game &p_game) const
{
    return this->isOnScreen(p_game.camera);
}

const bool Tile::isOnScreen(sf::View &p_camera) const
{
    sf::Vector2f center = p_camera.getCenter(), size = p_camera.getSize();
    return m_hitbox.getGlobalBounds().intersects(sf::FloatRect(center.x - size.x / 2, center.y - size.y / 2, size.x, size.y));
}

void Tile::setX(float p_x)
{
    this->setPos(p_x, this->getPos().y);
}

void Tile::setY(float p_y)
{
    this->setPos(this->getPos().x, p_y);
}

void Tile::setPos(float p_x, float p_y)
{
    this->setPos(sf::Vector2f(p_x, p_y));
}

void Tile::setPos(sf::Vector2f p_pos)
{
    this->m_pos = p_pos;
    this->m_hitbox.setPosition(p_pos);
    this->m_sprite.setPosition(p_pos);
}

const sf::Vector2f Tile::getPos() const
{
    return this->m_pos;
}

void Tile::draw(sf::RenderTarget *p_target) const
{
    p_target->draw(m_sprite);
}
