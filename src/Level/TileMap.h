#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include <vector>

class TileMap
{
    public:

    void draw(sf::RenderTarget* p_target, sf::View& p_view) const;

    private:
    std::vector<Tile> m_tiles;
};

#endif // TILEMAP_H
