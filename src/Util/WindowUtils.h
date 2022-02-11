#ifndef WINDOWUTILS_H
#define WINDOWUTILS_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Level/Level.h"
#include "Util/Structs.h"

void setCameraPositionRelativeToSprite(Game& game, const sf::Sprite& p_sprite);

void setCameraPositionRelativeToSpriteAndLevel(Game& game, const sf::Sprite& p_sprite, const Level& p_level);

#endif // WINDOWUTILS_H
