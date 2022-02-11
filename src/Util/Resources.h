#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SoundResource
{
    public:
    bool loadFromFile(std::string p_soundFile);

    sf::SoundBuffer buffer;
    sf::Sound sound;
};

class Resources
{
    public:
    bool loadFont(std::string p_key, std::string p_file);
    bool loadMusic(std::string p_key, std::string p_file);
    bool loadSound(std::string p_key, std::string p_file);
    bool loadTexture(std::string p_key, std::string p_file);

    std::map<std::string, sf::Font> fonts;
    std::map<std::string, sf::Music> music;
    std::map<std::string, SoundResource> sounds;
    std::map<std::string, sf::Texture> textures;
};

bool loadResources(Resources& p_resources);

#endif // RESOURCES_H
