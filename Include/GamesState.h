#pragma once

#include <cstdint>

namespace GameState {
	class GameState
	{
	private:
	
		uint32_t m_score;
		uint32_t m_lives;
		uint32_t m_combo;
		uint32_t m_level;
		
		std::chrono::time_point<std::chrono::steady_clock> m_start_time;

		KeyQueue::KeyQueue kq;

	public:
		GameState();
		int removeLive();
		int addLife();

		int setLevel(int newLevel);

		void resetCombo();

		// might remove time from calculation
		// used together as score_to_add := level * combo * time 
		auto getTime(){return m_start_time;};
		uint32_t getCombo(){return m_combo;};
		uint32_t getLevel(){return m_level;}; // also used to set level := getLevel() +/- 1
		
	};
};

