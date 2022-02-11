#include "Player.h"

#include <cmath>

Player::Player(const float p_gravity, const float p_jumpPower, const float p_leftRight, const float p_slowDownFactor, sf::Sound* p_jumpSound)
: m_gravity(p_gravity), m_jumpPower(p_jumpPower), m_leftRight(p_leftRight), m_slowDownFactor(p_slowDownFactor), m_jumpSound(nullptr)
{
    m_jumpSound = p_jumpSound;
}

void Player::update(Level p_level, InputMap p_inputMap)
{
    if ((p_inputMap.keyboard[sf::Keyboard::Up] || p_inputMap.keyboard[sf::Keyboard::W] || p_inputMap.keyboard[sf::Keyboard::Space] ) && m_falling > -3)
    {
        m_yVelocity = -m_jumpPower;
        m_jumpSound->play();
    }

    if (p_inputMap.keyboard[sf::Keyboard::Left] || p_inputMap.keyboard[sf::Keyboard::A])
        m_xVelocity -= m_leftRight;

    if (p_inputMap.keyboard[sf::Keyboard::Right] || p_inputMap.keyboard[sf::Keyboard::D])
        m_xVelocity += m_leftRight;

    m_xVelocity *= m_slowDownFactor;
    m_yVelocity += m_gravity;
    
    float xyVeloAbs = abs(m_xVelocity) + abs(m_yVelocity);
    float lastValue;
    m_falling -= 1;

    for (int i = 0; i < xyVeloAbs; i++)
    {
        lastValue = getX();
        setX(getX() + m_xVelocity / xyVeloAbs);
        if (p_level.isSpriteColliding(getHitbox()))
        {
            setX(lastValue);
            m_xVelocity = 0;
            break;
        }
    }

    for (int i = 0; i < xyVeloAbs; i++)
    {
        lastValue = getY();
        setY(getY() + m_yVelocity / xyVeloAbs);
        if (p_level.isSpriteColliding(getHitbox()))
        {
            setY(lastValue);
            if (m_yVelocity > 0) m_falling = 0;
            m_yVelocity = 0;
            break;
        }
    }

    mFunc_updateEntity();
}

const bool Player::isFalling() const
{
    return m_yVelocity > 0;
}
