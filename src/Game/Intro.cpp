#include "Intro.h"

Intro::Intro()
{}

Intro::~Intro() 
{}

void Intro::init(sf::Font& p_textFont, sf::Window* p_window)
{
    m_textFont = p_textFont;

    m_warningText.setFont(p_textFont);
    m_warningText.setFillColor(sf::Color(255, 255, 255, 0));
    m_warningText.setStyle(sf::Text::Bold);
    m_warningText.setString("Disclaimer\nThis game contains bright\nflashing lights. Do not play\nif you suffer from epilepsy\nAlso bad language warning so\nleave if you don't like it b****");
    m_warningText.setCharacterSize(48);
    m_warningText.setOrigin(sf::Vector2f(m_warningText.getGlobalBounds().width/2, m_warningText.getGlobalBounds().height/2));
    m_warningText.setPosition(sf::Vector2f(((float)p_window->getSize().x)/2, ((float)p_window->getSize().y)/2));

    m_pythonText.setFont(p_textFont);
    m_pythonText.setFillColor(sf::Color(255, 255, 255, 0));
    m_pythonText.setStyle(sf::Text::Bold);
    m_pythonText.setString("No valid Python installation was detected\nVersion 3.9 or higher is required for some fetures\nDownload Python from:\nhttps://www.python.org/downloads/");
    m_pythonText.setOrigin(sf::Vector2f(m_pythonText.getGlobalBounds().width/2, m_pythonText.getGlobalBounds().height/2));
    m_pythonText.setPosition(sf::Vector2f(((float)p_window->getSize().x)/2, ((float)p_window->getSize().y)/2));
}

void Intro::update(Game& game)
{
    switch (m_introStage)
    {
        // Setup
        case 0:
        m_timer.restart();
        m_introStage = 1;
        break;

        // Epilepsy warning fade in
        case 1:
        {
            if (game.input.mouseButton[sf::Mouse::Left] && !m_preLeft)
            {
                m_timer.restart();
                m_introStage = 7;
                m_alpha = 0;
                m_preLeft = true;
            }
            m_preLeft = game.input.mouseButton[sf::Mouse::Left];
            ++m_alpha;
            m_warningText.setFillColor(sf::Color(255, 255, 255, m_alpha));
            if (m_warningText.getFillColor().a >= 255)
            {
                m_warningText.setFillColor(sf::Color(255, 255, 255, 255));
                m_introStage = 2;
                m_timer.restart();
            }
        }
        break;

        // Epilepsy warning wait
        case 2:
        {
            if (game.input.mouseButton[sf::Mouse::Left] && !m_preLeft)
            {
                m_timer.restart();
                m_introStage = 7;
                m_alpha = 0;
            }
            m_preLeft = game.input.mouseButton[sf::Mouse::Left];
            if (m_timer.getElapsedTime().asMilliseconds() >= 5000)
            {
                m_alpha = 255;
                m_timer.restart();
                m_introStage = 3;
            }
        }
        break;

        // Epilepsy warning fade out
        case 3:
        {
            if (game.input.mouseButton[sf::Mouse::Left] && !m_preLeft)
            {
                m_warningText.setFillColor(sf::Color(255, 255, 255, 0));
                m_timer.restart();
                m_introStage = 7;
                m_alpha = 0;
                m_preLeft = true;
            }
            m_preLeft = game.input.mouseButton[sf::Mouse::Left];
            --m_alpha;
            m_warningText.setFillColor(sf::Color(255, 255, 255, m_alpha));
            if (m_warningText.getFillColor().a <= 0)
            {
                m_warningText.setFillColor(sf::Color(255, 255, 255, 0));
                m_timer.restart();
                m_introStage = 7;
                m_alpha = 0;
            }
        }
        break;

        // Python fade in
        case 4:
        {
            if (game.input.mouseButton[sf::Mouse::Left] && !m_preLeft)
            {
                m_timer.restart();
                m_introStage = 7;
                m_alpha = 0;
            }
            m_preLeft = game.input.mouseButton[sf::Mouse::Left];
            ++m_alpha;
            m_pythonText.setFillColor(sf::Color(255, 255, 255, m_alpha));
            if (m_pythonText.getFillColor().a >= 255)
            {
                m_pythonText.setFillColor(sf::Color(255, 255, 255, 255));
                m_introStage = 5;
                m_timer.restart();
            }
        }
        break;

        // Python wait
        case 5:
        {
            if (game.input.mouseButton[sf::Mouse::Left] && !m_preLeft)
            {
                m_timer.restart();
                m_introStage = 7;
                m_alpha = 0;
            }
            m_preLeft = game.input.mouseButton[sf::Mouse::Left];
            if (m_timer.getElapsedTime().asMilliseconds() >= 5000)
            {
                m_alpha = 255;
                m_timer.restart();
                m_introStage = 6;
            }
        }
        break;

        // Python fade out
        case 6:
        {
            if (game.input.mouseButton[sf::Mouse::Left] && !m_preLeft)
            {
                m_pythonText.setFillColor(sf::Color(255, 255, 255, 0));
                m_timer.restart();
                m_introStage = 7;
                m_alpha = 0;
                m_preLeft = true;
            }
            m_preLeft = game.input.mouseButton[sf::Mouse::Left];
            --m_alpha;
            m_pythonText.setFillColor(sf::Color(255, 255, 255, m_alpha));
            if (m_pythonText.getFillColor().a <= 0)
            {
                m_pythonText.setFillColor(sf::Color(255, 255, 255, 0));
                m_timer.restart();
                m_introStage = 7;
                m_alpha = 0;
            }
        }
        break;

        // Go to menu
        case 7:
        {
            game.data.state = MENU;
        }
        break;
    }
}

void Intro::draw(sf::RenderTarget* p_target) const
{
    switch (m_introStage)
    {
        case 1:
        case 2:
        case 3:
        p_target->draw(m_warningText);
        break;

        case 4:
        case 5:
        case 6:
        p_target->draw(m_pythonText);
        break;
    }
}
