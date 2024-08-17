#include <chrono>

#include <SFML/Graphics.hpp>
#include "sfml_testing.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 600), "Keyboard Warrior");

    const auto timeToEndScreen{std::chrono::seconds(2)}; // Time it should take for something to go from left-side to right-side

    const auto startTime{std::chrono::steady_clock::now()};

    float inc = 0.f;
    float x = 0.f;
    while (window.isOpen())
    {
        if(x >= 1800.f){inc = -5.f;}
        else if(x<=0){inc = 5.f;}
        x += inc;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        const auto currentTime{std::chrono::steady_clock::now()};
        const auto percentage = (currentTime - startTime) / timeToEndScreen; // Perentage of screen traveled
        Test::drawCircle(100.f, x, 600/2, window);
        Test::drawText("./coolvetica rg.otf", window);
        window.display();
    }

    return 0;
}