#include <SFML/Graphics.hpp>

// File for testing new features and adding documentation

// Shape set position based on top-left
// Make sure to set origin to center for EVERY ENTITY


// Most of the time, classes should have a draw method
// avoids calling window.draw() in main & access violations
class Test {
    public:
        // Shape is an abstract class, in order to return any shape and 
        // call its virtual methods we must return a pointer.
        static void drawCircle(float radius, float x, float y, sf::RenderWindow& window) {
                
                sf::CircleShape circle(radius);

                circle.setFillColor(sf::Color::Green);
                circle.setOrigin(radius, radius);
                circle.setPosition(x, y);

                window.draw(circle);

                return;
            }
        // Couldn't get it to draw to window if I just returned the text
        // So draw within function instead of outside
        // Previous code:
        //     ...
        //      return text;
        // main.cpp:
        //   sf::Text text = Test::createText(fontFile) //name of old func, no window param since drawing manually
        //   ...
        //  window.draw(text);
        static void drawText(std::string fontFile, sf::RenderWindow& window) {
            sf::Text text;
            sf::Font font;
            if (!font.loadFromFile(fontFile)) {
                throw;
            }
            text.setPosition(0.f, 0.f);

            text.setFont(font);
            text.setString("Keyboard Warrior");
            text.setString(text.getString() + " Concatenation");
            text.setCharacterSize(24);

            text.setFillColor(sf::Color::White);

            text.setLetterSpacing(5.f);
            
            window.draw(text);
            return;
        }
};

