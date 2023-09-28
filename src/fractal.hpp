#pragma once

#include "vector2.hpp"
#include <complex>


class Fractal {

public:
    virtual sf::Color getColor(const Vector2& position, int zoom) = 0;

    virtual ~Fractal() = default;

};


class Mandelbrot : public Fractal {

public:
    sf::Color getColor(const Vector2& position, int zoom);

};


class BurningShip : public Fractal {

public:
    sf::Color getColor(const Vector2& position, int zoom);

};
