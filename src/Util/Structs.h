#ifndef STRUCTS_H
#define STRUCTS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

#include "Enums.h"

struct GameData
{
    GameState state = NONE;
    unsigned int levelNumber = 0;
};

struct InputMap
{
    std::map<sf::Keyboard::Key, bool> keyboard;
    std::map<sf::Mouse::Button, bool> mouseButton;
    sf::Vector2f mousePos;
};

#endif // STRUCTS_H
