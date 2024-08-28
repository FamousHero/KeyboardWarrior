#include "../Include/Key.h"
#include <chrono>

Key::Key(char key, std::chrono::duration<float, std::milli> start_time, std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> end_time)
	:m_key(key), m_start_time(start_time), m_end_time(end_time)
{

	
}

void Key::updatePosition(float screen_x, float screen_y) {
	m_text.setPosition(screen_x, screen_y);

}

bool Key::expired()
{
	const auto curr_time{std::chrono::steady_clock::now()};
	if (curr_time > m_end_time)
	{
		return true;
	}
	return false;
}

void Key::drawKey(sf::RenderWindow& window) {
	if (!m_font.loadFromFile("./coolvetica rg.otf")) {
		throw;
	}
	m_text.setFont(m_font);

	m_text.setString(std::string() + m_key);
	m_text.setCharacterSize(32);

	m_text.setFillColor(sf::Color::White);
	m_text.setLetterSpacing(5.f);
	window.draw(m_text);
}