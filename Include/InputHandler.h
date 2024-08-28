#pragma once


class GameState;

class InputHandler
{
	char m_current_key;

public:
	InputHandler();
	void setCurrentKey(char key_t);
	char getCurrentKey(){return m_current_key;};
	//bool isMatch(KeyQueue kq, GameState gs); no more kq
			
};


