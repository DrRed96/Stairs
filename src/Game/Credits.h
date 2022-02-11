#ifndef CREDITS_H
#define CREDITS_H

#include <SFML/Graphics.hpp>

#include "Game.h"

class Credits
{
    public:
    Credits();
    void init(Game& p_game, sf::Texture& p_backgroundTexture, sf::Font& p_font);

    void update();

    void draw(sf::RenderTarget* p_target) const;
    private:

    sf::Font m_font;
    sf::Text m_creditsText;
};

#endif // CREDITS_H
