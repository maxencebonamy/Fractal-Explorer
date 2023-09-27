#include "grid.hpp"
#include <cxxopts.hpp>


int main(int argc, char* argv[]) {

    cxxopts::Options options("Fractal Explorer", "");

    options.add_options()
        ("f,fractal", "Select the fractal (mandelbrot / burning-ship)", cxxopts::value<std::string>())
        ("c,cell-size", "Set the size of a cell (1 by default)", cxxopts::value<int>()->default_value("1"))
        ("fullscreen", "Set the window in fullscreen", cxxopts::value<bool>()->implicit_value("true")->default_value("false"));
    options.allow_unrecognised_options();

    auto result = options.parse(argc, argv);
    auto fractalName = result["fractal"].as<std::string>();
    float cellSize = result["cell-size"].as<int>();

    std::shared_ptr<Fractal> fractal;

    if (fractalName == "mandelbrot") {
        fractal = std::make_shared<Mandelbrot>();
    }
    else if (fractalName == "burning-ship") {
        fractal = std::make_shared<BurningShip>();
    }
    else {
        std::cout << "Error: fractal \"" << fractalName << "\" does not exist (the available fractals are \"mandelbrot\" and \"burning-ship\")." << std::endl;
    }

    bool fullscreen = result["fullscreen"].as<bool>();

    Vector2 windowSize = WINDOW_SIZE;

    if (fullscreen) {
        windowSize.setX(sf::VideoMode::getDesktopMode().width);
        windowSize.setY(sf::VideoMode::getDesktopMode().height);
    }
    sf::VideoMode videoMode = { (unsigned int)windowSize.getX(), (unsigned int)windowSize.getY() };
    auto flags = fullscreen ? sf::Style::Fullscreen : sf::Style::Titlebar | sf::Style::Close;

    sf::RenderWindow window(videoMode, WINDOW_TITLE, flags);
    window.setFramerateLimit(WINDOW_FPS);

    sf::Image icon;
    icon.loadFromFile("assets/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Grid grid { fractal, cellSize, windowSize };
    sf::Mouse mouse;

    grid.updateFractal();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
            else if (event.type == sf::Event::MouseWheelScrolled) grid.updateEvents(event.mouseWheelScroll.delta, mouse, window);
        }

        window.clear();

        grid.display(window);

        window.display();
    }

    return EXIT_SUCCESS;
}