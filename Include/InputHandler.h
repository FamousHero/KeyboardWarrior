#pragma once

namespace GameState {
	class GameState;
}

namespace KeyQueue {
	class KeyQueue;
}


namespace InputHander{

	class InputHandler
	{
		char m_current_key;

	public:
		InputHandler();
		void setCurrentKey(char key_t);
		bool isMatch(KeyQueue::KeyQueue, GameState::GameState);
			
	};

}

