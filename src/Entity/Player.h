#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Level/Level.h"
#include "Util/Structs.h"

class Player
: public Entity
{
    public:
    Player(const float p_gravity, const float p_jumpPower, const float p_leftRight, const float p_slowDownFactor, sf::Sound* p_jumpSound);

    void update(Level p_level, InputMap p_inputMap);

    const bool isFalling() const;

    private:

    sf::Sound* m_jumpSound;

    float m_xVelocity;
    float m_yVelocity;
    float m_falling;

    const float m_gravity;
    const float m_jumpPower;
    const float m_leftRight;
    const float m_slowDownFactor;
};

#endif // PLAYER_H
