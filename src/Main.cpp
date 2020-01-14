#include "Game.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Game::GetSingleton()->Init();
	
	int currentTick = 0;
	int lastTicks = 0;

	while(Game::GetSingleton()->IsGameRunning())
	{
		currentTick = SDL_GetTicks();
		float deltaTime = (float)(currentTick - lastTicks) / 1000.0;
		
		Game::GetSingleton()->ProcessInput();
		Game::GetSingleton()->Update(deltaTime);
		Game::GetSingleton()->Render();
		
		lastTicks = currentTick;
	}

	Game::GetSingleton()->Destroy();
	return 0;
}
