#pragma once

#include <cstdint>
#include <chrono>

#include "LinkedList.h"

class Key;

class GameState
{
private:
	
	uint32_t m_score;
	uint32_t m_lives;
	uint32_t m_combo;
	uint32_t m_level;
		
	std::chrono::time_point<std::chrono::steady_clock> m_start_time;

	// Need to access all Keys on each interation
	// Queue does not work. 
	// LL allows draw for each key.
	LinkedList m_key_linked_list;
	char m_current_key;

public:
	GameState();

	int removeLive();
	int addLife();

	int setLevel(int newLevel);
	void setScore(uint32_t score){m_score = score;};
	void setCombo(uint32_t combo) { m_combo = combo; };
	void setCurrentKey(char key_t){m_current_key= key_t;};

	void resetCombo();

	// might remove time from calculation
	// used together as score_to_add := level * combo * time 
	auto getTime(){return m_start_time;};
	uint32_t getCombo(){return m_combo;};
	uint32_t getLevel(){return m_level;}; // also used to set level := getLevel() +/- 1
	char getCurrentKey(){return m_current_key;};

	Node* getHead(){return m_key_linked_list.getHead(); };
	void addKeyNode(Key key, STEADY_CLOCK_DURATION end_time);
	void drawGUI(sf::RenderWindow& window);

private:
	void setTextDefaults(sf::Text& text_t, sf::Font& font_t);
};


