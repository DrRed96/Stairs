#include "Level.h"

#include "Util/Collision.h"

Level::Level()
{}

void Level::init(sf::Texture& p_forgroundTexture, sf::Texture& p_backgroundTexture)
{
    m_foregroundTexture = p_forgroundTexture;
    m_backgroundTexture = p_backgroundTexture;
    m_foreground.setTexture(m_foregroundTexture);
    m_background.setTexture(m_backgroundTexture);
}

const bool Level::isEntityColliding(const Entity& p_entity) const
{
    return Collision::PixelPerfectTest(m_foreground, p_entity.getHitbox());
}

const bool Level::isSpriteColliding(const sf::Sprite& p_sprite) const
{
    return Collision::PixelPerfectTest(m_foreground, p_sprite);
}

void Level::draw(sf::RenderTarget* p_target)
{
    p_target->draw(m_background);
    p_target->draw(m_foreground);
}

const sf::FloatRect Level::getGlobalBounds() const
{
    return m_foreground.getGlobalBounds();
}
