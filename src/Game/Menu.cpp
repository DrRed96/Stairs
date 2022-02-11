#include "Menu.h"

#include "Util/GameUtils.h"

Menu::Menu(sf::Music& p_menuTheme, sf::Music& p_rickroll)
: m_aboutMenu(false), m_menuTheme(p_menuTheme), m_rickroll(p_rickroll)
{}

Menu::~Menu()
{

}

void Menu::init(Game& p_game, sf::Texture& p_backgroundTexture, sf::Font& p_font)
{
    m_backgroundTexture = p_backgroundTexture;
    m_background.setTexture(p_backgroundTexture);
    
    m_font = p_font;

    m_singleplayerButton.setFont(p_font);
    m_multiplayerButton.setFont(p_font);
    m_aboutButton.setFont(p_font);
    m_exitButton.setFont(p_font);
    m_backButton.setFont(p_font);

    m_singleplayerButton.setFillColor(sf::Color(255, 255, 255, 255));
    m_multiplayerButton.setFillColor(sf::Color(255, 255, 255, 255));
    m_aboutButton.setFillColor(sf::Color(255, 255, 255, 255));
    m_exitButton.setFillColor(sf::Color(255, 255, 255, 255));
    m_backButton.setFillColor(sf::Color(255, 255, 255, 255));

    m_singleplayerButton.setCharacterSize(48);
    m_multiplayerButton.setCharacterSize(48);
    m_aboutButton.setCharacterSize(48);
    m_exitButton.setCharacterSize(48);
    m_backButton.setCharacterSize(48);

    m_singleplayerButton.setString("Singleplayer");
    m_multiplayerButton.setString("Multiplayer");
    m_aboutButton.setString("About");
    m_exitButton.setString("Exit");
    m_backButton.setString("Back");

    m_singleplayerButton.setStyle(sf::Text::Bold);
    m_multiplayerButton.setStyle(sf::Text::Bold);
    m_aboutButton.setStyle(sf::Text::Bold);
    m_exitButton.setStyle(sf::Text::Bold);
    m_backButton.setStyle(sf::Text::Bold);

    m_singleplayerButton.setOrigin(m_singleplayerButton.getGlobalBounds().width/2, m_singleplayerButton.getGlobalBounds().height/2);
    m_multiplayerButton.setOrigin(m_multiplayerButton.getGlobalBounds().width/2, m_multiplayerButton.getGlobalBounds().height/2);
    m_aboutButton.setOrigin(m_aboutButton.getGlobalBounds().width/2, m_aboutButton.getGlobalBounds().height/2);
    m_exitButton.setOrigin(m_exitButton.getGlobalBounds().width/2, m_exitButton.getGlobalBounds().height/2);
    m_backButton.setOrigin(m_backButton.getGlobalBounds().width/2, m_backButton.getGlobalBounds().height/2);

    m_singleplayerButton.setPosition(p_game.window->getSize().x/2, 320);
    m_multiplayerButton.setPosition(p_game.window->getSize().x/2, 370);
    m_aboutButton.setPosition(p_game.window->getSize().x/2, 420);
    m_exitButton.setPosition(p_game.window->getSize().x/2, 470);
    m_backButton.setPosition(p_game.window->getSize().x/2, 590);

    m_aboutTextBackground.setFillColor(sf::Color(0, 0, 0, 200));
    m_aboutTextBackground.setSize(sf::Vector2f(p_game.window->getSize().x - 40, p_game.window->getSize().y - 310));
    m_aboutTextBackground.setOrigin(sf::Vector2f(m_aboutTextBackground.getGlobalBounds().width/2, m_aboutTextBackground.getGlobalBounds().height/2));
    m_aboutTextBackground.setPosition(sf::Vector2f(p_game.window->getSize().x/2, p_game.window->getSize().y/2 + 90));

    m_aboutText.setFont(m_font);
    m_aboutText.setFillColor(sf::Color(255, 255, 255, 255));
    m_aboutText.setCharacterSize(24);
    m_aboutText.setStyle(sf::Text::Bold);
    m_aboutText.setString("Made by Cal (DrRed96)\n\nLanguages: C/C++, Python\n\nLibraries: SFML, Python C API, JsonCpp\n\nTools: Microsoft Visual Studio Code, MinGW GCC, GNU Make\n\nThis is not an open source project so don't ask for the source code.\nHowever feel free to distribute it.");
    m_aboutText.setPosition(sf::Vector2f(50, 270));

    m_menuTheme.setVolume(50);
    m_menuTheme.play();
}

void Menu::update(Game& p_game)
{
    if (!m_aboutMenu)
    {
        if (isMouseIntersecting(p_game.input.mousePos, m_singleplayerButton.getGlobalBounds()))
        {
            m_singleplayerButton.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
            if (p_game.input.mouseButton[sf::Mouse::Left])
            {
                if (m_rickroll.getStatus() != sf::Music::Status::Playing)
                {
                    m_menuTheme.stop();
                    m_rickroll.play();
                    m_singleplayerButton.setString("RICKROLLED L");
                    m_singleplayerButton.setOrigin(m_singleplayerButton.getGlobalBounds().width/2, m_singleplayerButton.getGlobalBounds().height/2);
                    m_multiplayerButton.setString("Play");
                    m_multiplayerButton.setOrigin(m_multiplayerButton.getGlobalBounds().width/2, m_multiplayerButton.getGlobalBounds().height/2);
                }
            }
        }
        else
        {
            m_singleplayerButton.setFillColor(sf::Color(255, 255, 255, 255));
        }

        if (isMouseIntersecting(p_game.input.mousePos, m_multiplayerButton.getGlobalBounds()))
        {
            m_multiplayerButton.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
            if (p_game.input.mouseButton[sf::Mouse::Left])
            {
                if (m_menuTheme.getStatus() == sf::Music::Status::Playing) m_menuTheme.stop();
                if (m_rickroll.getStatus() == sf::Music::Status::Playing) m_rickroll.stop();
                p_game.data.state = GAME;
            }
        }
        else
        {
            m_multiplayerButton.setFillColor(sf::Color(255, 255, 255, 255));
        }

        if (isMouseIntersecting(p_game.input.mousePos, m_aboutButton.getGlobalBounds()))
        {
            m_aboutButton.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
            if (p_game.input.mouseButton[sf::Mouse::Left])
            {
                m_aboutMenu = true;
            }
        }
        else
        {
            m_aboutButton.setFillColor(sf::Color(255, 255, 255, 255));
        }

        if (isMouseIntersecting(p_game.input.mousePos, m_exitButton.getGlobalBounds()))
        {
            m_exitButton.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
            if (p_game.input.mouseButton[sf::Mouse::Left])
            {
                p_game.window->close();
            }
        }
        else
        {
            m_exitButton.setFillColor(sf::Color(255, 255, 255, 255));
        }
    }
    else
    {
        if (isMouseIntersecting(p_game.input.mousePos, m_backButton.getGlobalBounds()))
        {
            m_backButton.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
            if (p_game.input.mouseButton[sf::Mouse::Left])
            {
                m_aboutMenu = false;
            }
        }
        else
        {
            m_backButton.setFillColor(sf::Color(255, 255, 255, 255));
        }
    }
}

void Menu::draw(sf::RenderTarget* p_target)
{
    p_target->draw(m_background);
    if (!m_aboutMenu)
    {
        p_target->draw(m_singleplayerButton);
        p_target->draw(m_multiplayerButton);
        p_target->draw(m_aboutButton);
        p_target->draw(m_exitButton);
    }
    else
    {
        p_target->draw(m_aboutTextBackground);
        p_target->draw(m_aboutText);
        p_target->draw(m_backButton);
    }
}
