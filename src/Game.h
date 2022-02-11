#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Util/Resources.h"
#include "Util/Structs.h"

class Game
{
    public:
    Game();
    virtual ~Game();

    void pollWindowEvents();
    void log(std::string p_log);
    void saveLogs(std::string p_log);

    sf::RenderWindow* window;
    sf::View camera;

    GameData data;
    Resources resources;
    InputMap input;

    private:
    std::vector<std::string> m_logs;
};

#endif // GAME_H