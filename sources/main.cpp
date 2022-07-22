#include "grid.h"


int main() {

    sf::VideoMode videoMode { (unsigned int)WINDOW_SIZE.getX(), (unsigned int)WINDOW_SIZE.getY() };
    sf::RenderWindow window(videoMode, WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(WINDOW_FPS);

    sf::Image icon;
    icon.loadFromFile("dependencies/assets/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Grid grid;
    sf::Mouse mouse;

    grid.updateFractal();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            else if (event.type == sf::Event::MouseWheelScrolled) grid.updateEvents(event.mouseWheelScroll.delta, mouse, window);
        }

        window.clear();

        grid.display(window);

        window.display();
    }

    return EXIT_SUCCESS;
}