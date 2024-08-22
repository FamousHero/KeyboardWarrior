#pragma once

#include <queue>
#include <chrono>

#define MILLISECONDS std::chrono::milliseconds 

namespace KeyQueue {

	class KeyQueue
	{

		std::queue<char> m_key_queue;
		std::queue<std::chrono::time_point<std::chrono::duration<MILLISECONDS>>> m_time_queue;
		
		int speed;

	public:
		int getSpeed(){return speed;};
		char popKey();
		std::chrono::time_point<std::chrono::duration<MILLISECONDS>> popKeyTiming();
	};
};
