#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Game.h"

class Entity
{
    public:
    Entity();

    void init(sf::Texture& p_spriteTexture, sf::Texture& p_hitboxTexture);
    void initAnimations(std::string p_jsonFile);

    void draw(sf::RenderTarget* p_target, sf::View& camera) const;
    void draw(sf::RenderTarget& p_target, sf::View& camera) const;

    const sf::Sprite getHitbox() const;

    void setPos(sf::Vector2f p_pos);
    void setX(float p_x);
    void setY(float p_y);

    const sf::Vector2f getPos() const;
    const float getX() const;
    const float getY() const;

    const bool isDead() const;
    void kill();
    void setDead(bool p_dead);

    const bool isOnScreen(Game& p_game) const;
    const bool isOnScreen(sf::View& p_camera) const;

    protected:
    void mFunc_updateEntity(bool p_anim = false);

    private:
    void mFunc_updateAnimations();

    bool m_isDead;

    sf::Texture m_spriteTexture;
    sf::Texture m_hitboxTexture;

    sf::Sprite m_hitbox; // I wanted to make it an sf::RectangeShape but it doesn't work with the collision library
    sf::Sprite m_sprite;

    sf::Vector2f m_pos;

    bool m_isAnimated;
    sf::Clock m_animationTimer;
    int m_animationInterval;
    std::vector<sf::IntRect> m_animationRects;
    unsigned int m_currentAnimationFrame;
};

#endif // ENTITY_H
