#include "Resources.h"

bool SoundResource::loadFromFile(std::string p_soundFile)
{
    bool success = buffer.loadFromFile(p_soundFile);
    if (success) sound.setBuffer(buffer);
    return success;
}

bool Resources::loadFont(std::string p_key, std::string p_file)
{
    printf("Loading Resource: %s\n", p_file.c_str());
    return fonts[p_key].loadFromFile(p_file);
}

bool Resources::loadMusic(std::string p_key, std::string p_file)
{
    printf("Loading Resource: %s\n", p_file.c_str());
    bool success = music[p_key].openFromFile(p_file);
    music[p_key].setLoop(true);
    return success;
}

bool Resources::loadSound(std::string p_key, std::string p_file)
{
    printf("Loading Resource: %s\n", p_file.c_str());
    return sounds[p_key].loadFromFile(p_file);
}

bool Resources::loadTexture(std::string p_key, std::string p_file)
{

    printf("Loading Resource: %s\n", p_file.c_str());
    return textures[p_key].loadFromFile(p_file);
}

bool loadResources(Resources& p_resources)
{
    if (!p_resources.loadFont("times", "assets/fonts/times.ttf")) return false;

    if (!p_resources.loadMusic("giant_disco", "assets/audio/music/giant_disco.wav")) return false;
    if (!p_resources.loadMusic("rickroll", "assets/audio/music/rickroll.ogg")) return false;

    if (!p_resources.loadSound("jump", "assets/audio/effects/jump.ogg")) return false;

    if (!p_resources.loadTexture("bob", "assets/img/bob.png")) return false;
    if (!p_resources.loadTexture("empty", "assets/img/empty.png")) return false;
    if (!p_resources.loadTexture("lvl_0_fg", "assets/levels/0_fg.png")) return false;
    if (!p_resources.loadTexture("lvl_1_fg", "assets/levels/1_fg.png")) return false;
    if (!p_resources.loadTexture("menu_background", "assets/img/stairsbg.png")) return false;
    if (!p_resources.loadTexture("sample_player", "assets/img/sample_player.png")) return false;

    return true;
}
