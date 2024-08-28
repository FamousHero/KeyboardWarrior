#pragma once

#include <chrono>

class GameState;

class InputHandler
{
	std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> m_time_out;
public:
	InputHandler();
	void setCurrentKey(char key_t, GameState& gs);
	void setTimeOut(std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> time_out_t){m_time_out = time_out_t;};
	std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> getTimeOut(){return m_time_out;};
	//bool isMatch(KeyQueue kq, GameState gs); no more kq
			
};


