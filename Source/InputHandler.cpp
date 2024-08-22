#include "../Include/InputHandler.h"

#include "../Include/KeyQueue.h"
#include "../Include/GamesState.h"

InputHander::InputHandler::InputHandler()
	:m_current_key('\0')
{
}

void InputHander::InputHandler::setCurrentKey(char key_t)
{
	m_current_key = key_t;
}

bool InputHander::InputHandler::isMatch(KeyQueue::KeyQueue, GameState::GameState)
{
	//Big class imp
	return false;
}
