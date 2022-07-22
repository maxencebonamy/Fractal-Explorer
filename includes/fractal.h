#ifndef FRACTAL_EXPLORER_FRACTAL_H
#define FRACTAL_EXPLORER_FRACTAL_H

#include "vector2.h"
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


#endif
