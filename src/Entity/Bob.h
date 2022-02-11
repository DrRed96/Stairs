#ifndef BOB_H
#define BOB_H

#include "Entity/Entity.h"
#include "Entity/Player.h"
#include "Level/Level.h"

class Bob
: public Entity
{
    public:
    Bob(const float p_gravity, const float p_leftRight, const float p_slowDownFactor);

    void update(Level& p_level, Player& p_player);
    private:

    float m_xVelocity;
    float m_yVelocity;
    float m_falling;

    const float m_gravity;
    const float m_leftRight;
    const float m_slowDownFactor;

};

#endif // BOB_H