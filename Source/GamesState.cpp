#include "../Include/GamesState.h"
#include "../Include/Key.h"


GameState::GameState()
	:m_score(0), m_lives(0), m_combo(0), m_level(0)
{
}

int GameState::removeLive()
{
	m_lives -= 1;
	return m_lives;
}

int GameState::addLife()
{
	m_lives += 1;
	return m_lives;
}

int GameState::setLevel(int newLevel)
{
	m_level = newLevel;
	return m_level;
}

void GameState::resetCombo()
{
	m_combo = 0;
}

void GameState::addKeyNode(Key key, STEADY_CLOCK_DURATION end_time)
{
	m_key_linked_list.addNode(key, end_time);
	return;
}

void GameState::drawGUI(sf::RenderWindow& window)
{
	sf::Font font;
	if(!font.loadFromFile("./coolvetica rg.otf"))
		throw;
	sf::Text score;
	sf::Text lives;
	sf::Text combo;


	score.setString("Score: 120");
	setTextDefaults(score, font);
	score.setPosition(1600.f, 20.f);

	lives.setString("Lives: 3");
	setTextDefaults(lives, font);
	lives.setPosition(1600.f/2, 20.f);

	combo.setString(" x31");
	setTextDefaults(combo, font);
	combo.setPosition(100.f, 20.f);

	window.draw(score);
	window.draw(lives);
	window.draw(combo);
}

void GameState::setTextDefaults(sf::Text& text_t, sf::Font& font_t)
{
	text_t.setFont(font_t);

	text_t.setCharacterSize(32);

	text_t.setFillColor(sf::Color::White);
	text_t.setLetterSpacing(5.f);

	sf::FloatRect bounds = text_t.getGlobalBounds();
	sf::Vector2f topLeft = bounds.getPosition();
	sf::Vector2f size = bounds.getSize();

	text_t.setOrigin(topLeft.x+size.x/2, topLeft.y-size.y/2);
}

