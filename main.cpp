#include <chrono>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Source/sfml_testing.cpp"

#include "Include/GamesState.h"
#include "Include/InputHandler.h"
#include "Include/KeyQueue.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 600), "Keyboard Warrior");

    const float timeToEndScreen{4.f}; // Time it should take for something to go from left-side to right-side
    auto startTime{std::chrono::steady_clock::now()};
    float x = 0.f;
    
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        const auto currentTime{std::chrono::steady_clock::now()};
        std::chrono::duration<float, std::milli> elapsedTime = currentTime - startTime; // Ticks elapsed in microseconds
        elapsedTime = elapsedTime / 1000.f;
        auto percentage = elapsedTime.count() / timeToEndScreen; // Perentage of screen traveled
        // If at the edge of screen, reset start time and subtract percentage from 1
        float inc = 0.f;

        inc = (x == 0.f)? percentage: 1.f - percentage;

        if (percentage >= 1.f) {
            startTime = std::chrono::steady_clock::now();
            if (x == 0.f) {
                x = 1.f;
            }
            else if (x == 1.f) {
                x = 0.f;
            }
        }
        std::cout << percentage << "\n";
        Test::drawCircle(100.f, 1800.f*inc, 600/2, window);
        Test::drawText("./coolvetica rg.otf", window);
        window.display();
    }

    return 0;
}