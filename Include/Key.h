#pragma once
#include <SFML/graphics.hpp>
#include <chrono>

class Key
{
	char m_key;
	sf::Text m_text;
	sf::Font m_font;
	std::chrono::duration<float, std::milli> m_start_time;
	std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> m_end_time;


public:
	Key(char key, std::chrono::duration<float, std::milli> start_time, std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> end_time);
	void updatePosition(float screen_x, float screen_y);
	bool expired();
	char getKey(){return m_key;};
	void setKey(char key_t){m_key = key_t;};
	void drawKey(sf::RenderWindow& window);

};
