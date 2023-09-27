#pragma once

#include "config.hpp"
#include <memory>

class Grid {

public:
    Grid(std::shared_ptr<Fractal> fractal, float cellSize, const Vector2& windowSize);

    void updateFractal();

    void display(sf::RenderWindow& window);

    void updateEvents(int delta, const sf::Mouse& mouse, const sf::RenderWindow& window);

private:
    const std::shared_ptr<Fractal> _fractal;
    const float _cellSize;

    const Vector2& _windowSize;
    Vector2& _size = Vector2();

    sf::Texture _texture;
    std::vector<sf::Uint8> _pixels;

    sf::Sprite _sprite;

    Vector2 _posMin { -2.5, -1 },
            _posMax { 1.5, 1};

    const float zoomMin { 20 }, zoomMax { 100 };

    int _zoom { 0 };
};
