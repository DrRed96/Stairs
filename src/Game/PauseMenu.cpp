#include "PauseMenu.h"

PauseMenu::PauseMenu()
{

}

void PauseMenu::init(sf::Window& p_window, sf::Font& p_font)
{
    m_font = p_font;

    m_background.setFillColor(sf::Color(0, 0, 0, 185));
    m_background.setSize(sf::Vector2f((float)p_window.getSize().x, (float)p_window.getSize().y));
}

void PauseMenu::update(sf::Window& p_window, InputMap& p_input, GameData& p_gameData)
{

}

void PauseMenu::setPaused(bool p_paused)
{
    m_isPaused = p_paused;
}

void PauseMenu::draw(sf::RenderTarget& p_target) const
{
    if (m_isPaused)
    {
        p_target.draw(m_background);
    }
}
