#include "GameUtils.h"

#include <cstdlib>
#include <json.h>
#include <fstream>
#include <SFML/Audio.hpp>

#include "Logger.h"

GameData loadGameDataFromJson(std::string filePath)
{
    GameData gameData;
    std::ifstream jsonFileStream(filePath, std::ifstream::binary);
    Json::Value root;
    jsonFileStream >> root;

    switch (root["state"].asInt())
    {
        default:
        gameData.state = NONE;
        break;

        case 1:
        gameData.state = MENU;
        break;

        case 2:
        gameData.state = GAME;
        break;
    }

    gameData.levelNumber = root["levelNumber"].asUInt();

    return gameData;
}

bool isMouseIntersecting(const sf::Vector2i p_mousePos, const sf::IntRect p_rect)
{
    return (
        p_mousePos.x >= p_rect.left &&
        p_mousePos.x <= p_rect.left + p_rect.width &&
        p_mousePos.y >= p_rect.top &&
        p_mousePos.y <= p_rect.top + p_rect.height
    );
}

bool isMouseIntersecting(const sf::Vector2f p_mousePos, const sf::FloatRect p_rect)
{
    return (
        p_mousePos.x >= p_rect.left &&
        p_mousePos.x <= p_rect.left + p_rect.width &&
        p_mousePos.y >= p_rect.top &&
        p_mousePos.y <= p_rect.top + p_rect.height
    );
}

void stopAllMusic(Resources& p_resources)
{
    for (std::map<std::string, sf::Music>::iterator i = p_resources.music.begin(); i != p_resources.music.end(); i++)
    {
        if (i->second.Playing)
        {
            i->second.stop();
        }
    }
}

void quit(int p_code)
{
    Logger::saveLogs();
    exit(p_code);
}
