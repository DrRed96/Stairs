#include "Entity.h"

Entity::Entity()
{}

void Entity::init(sf::Texture& p_spriteTexture, sf::Texture& p_hitboxTexture)
{
    m_isDead = false;
    m_isAnimated = false;
    m_hitboxTexture = p_hitboxTexture;
    m_spriteTexture = p_spriteTexture;
    m_hitbox.setTexture(m_hitboxTexture);
    m_sprite.setTexture(m_spriteTexture);
    m_hitbox.setOrigin(sf::Vector2f(m_hitbox.getGlobalBounds().width/2, m_hitbox.getGlobalBounds().height/2));
    m_sprite.setOrigin(sf::Vector2f(m_hitbox.getGlobalBounds().width/2, m_hitbox.getGlobalBounds().height/2));
}

void Entity::initAnimations(std::string p_jsonFile)
{
    m_isAnimated = true;
    // TODO animation loading
}

void Entity::draw(sf::RenderTarget* p_target, sf::View& p_camera) const
{
    if (!m_isDead && isOnScreen(p_camera)) p_target->draw(m_sprite);
}

void Entity::draw(sf::RenderTarget& p_target, sf::View& p_camera) const
{
    if (!m_isDead && isOnScreen(p_camera)) p_target.draw(m_sprite);
}

const sf::Sprite Entity::getHitbox() const
{
    return m_hitbox;
}

void Entity::setPos(sf::Vector2f p_pos)
{
    m_pos = p_pos;
    m_hitbox.setPosition(m_pos);
}

void Entity::setX(float p_x)
{
    m_pos.x = p_x;
    m_hitbox.setPosition(m_pos);
}

void Entity::setY(float p_y)
{
    m_pos.y = p_y;
    m_hitbox.setPosition(m_pos);
}

const sf::Vector2f Entity::getPos() const
{
    return m_pos;
}

const float Entity::getX() const
{
    return m_pos.x;
}

const float Entity::getY() const
{
    return m_pos.y;
}

const bool Entity::isDead() const
{
    return m_isDead;
}

void Entity::kill()
{
    m_isDead = true;
}

void Entity::setDead(bool p_dead)
{
    this->m_isDead = p_dead;
}

const bool Entity::isOnScreen(Game& p_game) const
{
    return isOnScreen(p_game.camera);
}

const bool Entity::isOnScreen(sf::View& p_camera) const
{
    sf::Vector2f center = p_camera.getCenter(), size = p_camera.getSize();

    return m_hitbox.getGlobalBounds().intersects(sf::FloatRect(center.x-size.x/2, center.y-size.y/2, size.x, size.y));
}

void Entity::mFunc_updateEntity(bool p_anim)
{
    if (m_isDead) return;

    if (p_anim && m_isAnimated) mFunc_updateAnimations();
    m_hitbox.setPosition(m_pos);
    m_sprite.setPosition(m_pos);
}

void Entity::mFunc_updateAnimations()
{
    if (m_animationInterval <= m_animationTimer.getElapsedTime().asMilliseconds()) {
        m_animationTimer.restart();
        m_currentAnimationFrame++;
        if (m_currentAnimationFrame >= m_animationRects.size())
            m_currentAnimationFrame = 0;

        m_sprite.setTextureRect(m_animationRects[m_currentAnimationFrame]);
    }
}
