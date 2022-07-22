#ifndef MINESWEEPER_GRID_H
#define MINESWEEPER_GRID_H

#include "config.h"

class Grid {

public:
    Grid();

    void updateFractal();

    void display(sf::RenderWindow& window);

    void updateEvents(int delta, const sf::Mouse& mouse, const sf::RenderWindow& window);

private:
    sf::Color _getColor(const Vector2& position);

    const Vector2& _size { GRID_SIZE };

    sf::Texture _texture;
    std::vector<sf::Uint8> _pixels;

    sf::Sprite _sprite;

    Vector2 _posMin { -2.5, -1 },
            _posMax { 1.5, 1};

    const float zoomMin { 20 }, zoomMax { 100 };

    int _zoom { 0 };
};

#endif
