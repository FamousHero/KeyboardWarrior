#include "../Include/GamesState.h"

#include "../Include/KeyQueue.h"

GameState::GameState::GameState()
	:m_score(0), m_lives(0), m_combo(0), m_level(0),
	m_start_time(std::chrono::steady_clock::now())
{
}
int GameState::GameState::removeLive()
{
	m_lives -= 1;
	return m_lives;
}

int GameState::GameState::addLife()
{
	m_lives += 1;
	return m_lives;
}

int GameState::GameState::setLevel(int newLevel)
{
	m_level = newLevel;
	return m_level;
}

void GameState::GameState::resetCombo()
{
	m_combo = 0;
}

uint32_t GameState::GameState::getLevel()
{
	return 0;
}
