#ifndef GAMEUTILS_H
#define GAMEUTILS_H

#include "Structs.h"
#include "Resources.h"

GameData loadGameDataFromJson(std::string filePath);

bool isMouseIntersecting(const sf::Vector2i p_mousePos, const sf::IntRect p_rect);

bool isMouseIntersecting(const sf::Vector2f p_mousePos, const sf::FloatRect p_rect);

void stopAllMusic(Resources& p_resources);

void quit(int p_code);

#endif // GAMEUTILS_H