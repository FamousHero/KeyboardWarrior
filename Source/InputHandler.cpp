#include "../Include/InputHandler.h"

#include "../Include/GamesState.h"

 InputHandler::InputHandler()
	:m_current_key('\0')
{
}

void  InputHandler::setCurrentKey(char key_t)
{
	m_current_key = key_t;
}


