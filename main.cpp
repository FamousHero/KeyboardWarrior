#include <SFML/Graphics.hpp>
#include "sfml_testing.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 600), "Keyboard Warrior");



    sf::CircleShape circle = Test::CreateCircle(100.f, 1800.f/2, 600.f/2);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        Test::drawText("./coolvetica rg.otf", window);
        window.display();
    }

    return 0;
}