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

