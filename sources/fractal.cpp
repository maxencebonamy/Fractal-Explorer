#include "fractal.h"


sf::Color Mandelbrot::getColor(const Vector2& position, int zoom) {
    float x { position.getX() }, y { position.getY() };

//    double p { std::sqrt(std::pow(x - 0.25, 2) + std::pow(y, 2)) };
//
//    // Test si le point appartient à la cardioïde
//    if (x < p - 2 * std::pow(p, 2) + 0.25)
//        return sf::Color::Black;
//
//    // Test si le point appartient au bourgeon principal
//    if (std::pow(position.getX() + 1 , 2) + std::pow(position.getY(), 2) < 1 / 16)
//        return sf::Color::Black;

    std::complex<float> z;

    std::complex<float> c(x, y);

    int nbIter { 4 * std::max(0, zoom) + 20 };
    for (int i { 0 }; i < nbIter; ++i) {
        z = std::pow(z, 2) + c;

        if (std::pow(z.real(), 2) + std::pow(z.imag(), 2) > 4)
            return sf::Color(std::min(i*0, 255), std::min(i*10, 255), std::min(i*20, 255));
    }

    return sf::Color::Black;
}

sf::Color BurningShip::getColor(const Vector2& position, int zoom) {
    std::complex<float> z;

    std::complex<float> c(position.getX(), position.getY());

    int nbIter { 4 * std::max(0, zoom) + 20 };
    for (int i { 0 }; i < nbIter; ++i) {
        z = std::pow(std::complex<float>(std::abs(z.real()), std::abs(z.imag())), 2) + c;

        if (std::pow(z.real(), 2) + std::pow(z.imag(), 2) > 4)
            return sf::Color(std::min(i*15, 255), std::min(i*0, 255), std::min(i*0, 255));
    }

    return sf::Color::Black;
}
