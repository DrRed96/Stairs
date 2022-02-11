#ifndef INTRO_H
#define INTRO_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Util/Structs.h"

class Intro
{
    public:
    Intro();
    virtual ~Intro();

    void init(sf::Font& p_textFont, sf::Window* p_window);

    void update(Game& game);

    void draw(sf::RenderTarget* p_target) const;

    private:

    sf::Font m_textFont;
    sf::Text m_warningText;
    sf::Text m_pythonText;
    sf::Int8 m_alpha = 0;

    sf::Clock m_timer;

    unsigned int m_introStage = 0;
    bool m_preLeft = false;
};

#endif // INTRO_H
