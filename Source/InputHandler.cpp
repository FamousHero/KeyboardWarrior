#include "../Include/InputHandler.h"

#include "../Include/GamesState.h"

 InputHandler::InputHandler()
{
}

void  InputHandler::setCurrentKey(char key_t, GameState& gs)
{
	gs.setCurrentKey(key_t);
}



