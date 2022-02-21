#include "Game.h"

#include <ctime>
#include <fstream>

#include "Logger.h"

#include "Util/GameUtils.h"
#include "Util/SfmlUtils.h"

Game::Game()
{
    Logger::debug("Initializing Game", __FILE__, __LINE__);
    data.state = INTRO;
    data.levelNumber = 1;

    Logger::log("Initializing Window");
    window = new sf::RenderWindow(sf::VideoMode(800, 640), "I fell down the stairs while using Visual Studio Code and this is the game that showed up", sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(60);

    Logger::log("Loading Resources");
    if (!loadResources(resources))
        quit(1);

    Logger::log("Initializing Camera");
    camera.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
}

Game::~Game()
{
    delete window;
}

void Game::pollWindowEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:
            input.keyboard[event.key.code] = true;
            break;

        case sf::Event::KeyReleased:
            input.keyboard[event.key.code] = false;
            break;

        case sf::Event::MouseButtonPressed:
            input.mouseButton[event.mouseButton.button] = true;
            break;

        case sf::Event::MouseButtonReleased:
            input.mouseButton[event.mouseButton.button] = false;
            break;

        case sf::Event::MouseMoved:
            input.mousePos.x = event.mouseMove.x;
            input.mousePos.y = event.mouseMove.y;
            break;

        case sf::Event::MouseEntered:
            break;

        case sf::Event::MouseLeft:
            break;

        default:
            Logger::warning("Event type " + std::to_string(event.type) + " is unhandled (" + getEventName(event.type) + ")", __FILE__, __LINE__);
            break;
        }
    }
}

void Game::log(std::string p_log)
{
    printf("%s\n", p_log.c_str());
    m_logs.push_back(p_log);
}

void Game::saveLogs(std::string p_log)
{
    std::string logs = "";
    for (std::string str : m_logs)
    {
        logs += str;
        logs += "\n";
    }
    std::ofstream file("logs/" + std::to_string(time(0)) + ".log", std::ofstream::binary);
    file << logs;
    file.close();
    std::ofstream latest("logs/latest.log", std::ofstream::binary);
    latest << logs;
    latest.close();
}
