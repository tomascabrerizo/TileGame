#pragma once
#include <SDL.h>
#include "Constants.h"

class Game
{
private:

	static Game* s_Instance;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	bool m_isGameRunning;	

	//Player
	float playerX;
	float playerY;
	int playerSpeedX;
	int playerSpeedY;	
	Game();

public:
	GameError Init();
	void ProcessInput();
	void Update(float DeltaTime);
	void Render();
	
	void Destroy();

	static Game* GetSingleton();
	SDL_Renderer* GetRenderer();
	SDL_Window* GetWindow();
	bool IsGameRunning();
};
