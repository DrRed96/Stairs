#include "Bob.h"

#include "Util/Collision.h"

Bob::Bob(const float p_gravity, const float p_leftRight, const float p_slowDownFactor)
: m_gravity(p_gravity), m_leftRight(p_leftRight), m_slowDownFactor(p_slowDownFactor)
{}

void Bob::update(Level& p_level, Player& p_player)
{
    if (this->isDead()) return;

    if (p_player.getX() < this->getX())
        m_xVelocity -= m_leftRight;

    if (p_player.getX() > this->getX())
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

    if (Collision::BoundingBoxTest(this->getHitbox(), p_player.getHitbox()))
    {
        if (p_player.getY() < this->getY() && p_player.isFalling())
        {
            this->kill();
        }
        else
        {
            p_player.kill();
        }
    }

    mFunc_updateEntity();
}
