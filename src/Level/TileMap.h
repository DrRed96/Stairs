#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include "TileSet.h"
#include <vector>

class TileMap
{
    public:
    TileMap();
    void loadFromJson(std::string p_filePath);
    void loadFromBin(std::string p_filePath);

    void draw(sf::RenderTarget* p_target, sf::View& p_view) const;

    private:
    std::vector<Tile> m_tiles;
};

#endif // TILEMAP_H
