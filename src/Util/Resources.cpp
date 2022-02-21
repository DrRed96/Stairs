#include "Resources.h"

#include "Logger.h"

bool SoundResource::loadFromFile(std::string p_file)
{
    Logger::log("Loading file: " + p_file);
    bool success = buffer.loadFromFile(p_file);
    if (!success) Logger::log("Failed to load file: " + p_file);
    if (success) sound.setBuffer(buffer);
    return success;
}

bool Resources::loadFont(std::string p_key, std::string p_file)
{
    Logger::log("Loading file: " + p_file);
    bool success = fonts[p_key].loadFromFile(p_file);
    if (!success) Logger::error("Failed to load file: " + p_file, __FILE__, __LINE__);
    return success;
}

bool Resources::loadMusic(std::string p_key, std::string p_file)
{
    Logger::log("Loading file: " + p_file);
    bool success = music[p_key].openFromFile(p_file);
    if (!success) Logger::error("Failed to load file: " + p_file, __FILE__, __LINE__);
    music[p_key].setLoop(true);
    return success;
}

bool Resources::loadSound(std::string p_key, std::string p_file)
{
    Logger::log("Loading file: " + p_file);
    bool success = sounds[p_key].loadFromFile(p_file);
    if (!success) Logger::error("Failed to load file: " + p_file, __FILE__, __LINE__);
    return success;
}

bool Resources::loadTexture(std::string p_key, std::string p_file)
{
    Logger::log("Loading file: " + p_file);
    bool success = textures[p_key].loadFromFile(p_file);
    if (!success) Logger::error("Failed to load file: " + p_file, __FILE__, __LINE__);
    return success;
}

bool loadResources(Resources& p_resources)
{
    // Fonts
    if (!p_resources.loadFont("times", "assets/fonts/times.ttf")) return false;

    // Music
    if (!p_resources.loadMusic("giant_disco", "assets/audio/music/giant_disco.wav")) return false;
    if (!p_resources.loadMusic("rickroll", "assets/audio/music/rickroll.ogg")) return false;

    // Audio
    if (!p_resources.loadSound("jump", "assets/audio/effects/jump.ogg")) return false;

    // Textures
    if (!p_resources.loadTexture("bob", "assets/img/bob.png")) return false;
    if (!p_resources.loadTexture("empty", "assets/img/empty.png")) return false;
    if (!p_resources.loadTexture("lvl_0_fg", "assets/levels/0_fg.png")) return false;
    if (!p_resources.loadTexture("lvl_1_fg", "assets/levels/1_fg.png")) return false;
    if (!p_resources.loadTexture("menu_background", "assets/img/stairsbg.png")) return false;
    if (!p_resources.loadTexture("sample_player", "assets/img/sample_player.png")) return false;

    return true;
}
