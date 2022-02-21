#include "TileMap.h"

#include "Util/FileUtils.h"
#include <json.h>

void TileMap::loadFromJson(std::string p_filePath)
{
    Json::Value root = openFileJson(p_filePath);
}

void TileMap::loadFromBin(std::string p_filePath)
{
    try {
        std::string file = openFileBin(p_filePath);
        // 0 = Image, 1 = Size, 2 = Tilemap
        int stage = 0;
        std::string str;
        for (char c : file)
        {
            switch (stage)
            {

            }
        }
    } catch (const std::exception& exception) {
        
    }
}

void TileMap::draw(sf::RenderTarget *p_target, sf::View &p_view) const
{
    for (Tile t : m_tiles)
    {
        if (t.isOnScreen(p_view))
            t.draw(p_target);
    }
}
