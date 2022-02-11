#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Util/Structs.h"

class PauseMenu
{
    public:
    PauseMenu();

    void init(sf::Window& p_window, sf::Font& p_font);
    void update(sf::Window& p_window, InputMap& p_input, GameData& p_gameData);

    void setPaused(bool p_paused);

    void draw(sf::RenderTarget& p_target) const;
    private:

    sf::Font m_font;
    sf::Text m_resumeButton;

    sf::RectangleShape m_background;

    bool m_isPaused;
};

#endif // PAUSEMENU_H
