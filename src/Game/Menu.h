#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game.h"
#include "Util/Structs.h"

class Menu
{
    public:
    Menu(sf::Music& p_menuTheme, sf::Music& p_rickroll);
    virtual ~Menu();

    void init(Game& p_game, sf::Texture& p_backgroundTexture, sf::Font& p_font);
    void update(Game& p_game);

    void draw(sf::RenderTarget* p_target);
    
    private:

    bool m_aboutMenu;

    sf::Texture m_backgroundTexture;
    sf::Sprite m_background;

    sf::Font m_font;
    sf::Text m_singleplayerButton;
    sf::Text m_multiplayerButton;
    sf::Text m_aboutButton;
    sf::Text m_exitButton;
    sf::Text m_backButton;
    sf::Text m_aboutText;
    sf::RectangleShape m_aboutTextBackground;

    sf::Music& m_menuTheme;
    sf::Music& m_rickroll;
};

#endif // MENU_H
