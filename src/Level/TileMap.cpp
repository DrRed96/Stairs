#include "TileMap.h"

void TileMap::draw(sf::RenderTarget* p_target, sf::View& p_view) const
{
    for (Tile t : m_tiles)
    {
        if (t.isOnScreen(p_view)) t.draw(p_target);
    }
}
