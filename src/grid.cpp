#include "grid.hpp"


Grid::Grid(std::shared_ptr<Fractal> fractal, float cellSize, const Vector2& windowSize) :
    _fractal(std::move(fractal)),
    _cellSize(cellSize),
    _windowSize(windowSize)
{
    _size = _windowSize / _cellSize;

    _texture.create(_size.getX(), _size.getY());
    for (int i { 0 }; i < _size.getX() * _size.getY() * 4; ++i) _pixels.push_back(255);
    _texture.update(_pixels.data());
    _sprite.setTexture(_texture);
    _sprite.setScale(_cellSize, _cellSize);
}

void Grid::updateFractal() {

    sf::Uint8* ptr { _pixels.data() };
    for (int j { 0 }; j < _size.getY(); ++j) {
        for (int i { 0 }; i < _size.getX(); ++i) {
            Vector2 cellPos { Vector2(i, j) };

            Vector2 position { (_posMax - _posMin) / _size * cellPos + _posMin };
            sf::Color color { _fractal->getColor(position, _zoom) };

            *ptr++ = color.r;
            *ptr++ = color.g;
            *ptr++ = color.b;
            ptr++;
        }
    }

    _texture.update(_pixels.data());
    _sprite.setTexture(_texture);
}

void Grid::display(sf::RenderWindow& window) {
    window.draw(_sprite);
}

void Grid::updateEvents(int delta, const sf::Mouse& mouse, const sf::RenderWindow& window) {
    if (delta != 0) {
        float value { delta > 0 ? 0.75f : 1.33f };
        _zoom += delta > 0 ? 1 : -1 ;

        float factor { (float)std::pow(value, std::abs(delta)) };

        Vector2 mousePos { (float)mouse.getPosition(window).x, (float)mouse.getPosition(window).y };
        Vector2 point { (_posMax - _posMin) / _size * mousePos / _cellSize + _posMin };

        _posMin = point - (point - _posMin) * factor;
        _posMax = point + (_posMax - point) * factor;

        updateFractal();
    }
}