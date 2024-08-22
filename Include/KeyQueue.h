#pragma once

#include <queue>
#include <chrono>


namespace KeyQueue {

	class KeyQueue
	{

		std::queue<char> m_key_queue;
		std::queue<std::chrono::time_point<std::chrono::duration<float, std::milli>>> m_time_queue;
		
		int speed;

	public:
		int getSpeed(){return speed;};
		char popKey();
		std::chrono::time_point<std::chrono::duration<float, std::milli>> popKeyTiming();
	};
};
