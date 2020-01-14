#include "Game.h"
#include <iostream>

Game* Game::s_Instance = NULL;

Game::Game()
{
	m_isGameRunning = false;

	//Init Player
	playerX = WINDOW_WIDTH/2;
	playerY = WINDOW_HEIGHT/2;
	
	playerSpeedX = SPEED;
	playerSpeedY = SPEED;
}

GameError Game::Init()
{
	/*Init SDL and Create SDL Window*/
	SDL_Init(SDL_INIT_EVERYTHING);
	m_Window = SDL_CreateWindow(
			"2D_RPG",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_SHOWN
	);

	if(m_Window != 0)
	{
		/*Create SDL Renderer*/
		m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
	}
	else
	{
		return ErrorInitSDL; 
	}

	m_isGameRunning = true;
	return NoError;
}

void Game::ProcessInput()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				m_isGameRunning = false;
			break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_a:
						playerSpeedX = -SPEED;
					break;
					case SDLK_d:
						playerSpeedX = SPEED;
					break;
					case SDLK_w:
						playerSpeedY = -SPEED;
					break;
					case SDLK_s:
						playerSpeedY = SPEED;
					break;
				}
			break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym)
				{
					case SDLK_a:
						playerSpeedX = 0;
					break;
					case SDLK_d:
						playerSpeedX = 0;
					break;
					case SDLK_w:
						playerSpeedY = 0;
					break;
					case SDLK_s:
						playerSpeedY = 0;
					break;
				}
			break;
		}
	}
}

void Game::Update(float deltaTime)
{
	//Temp auto movement	
	if(playerX + 50 > WINDOW_WIDTH)
		playerSpeedX = -SPEED;
	if(playerX < 0)
		playerSpeedX = SPEED;

	if(playerY + 50 > WINDOW_HEIGHT)
		playerSpeedY = -SPEED;
	if(playerY < 0)
		playerSpeedY = SPEED;

	playerX += playerSpeedX * deltaTime;
	playerY += playerSpeedY	* deltaTime;
}

void Game::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);
	
	//Rendering Player as SDL_Rect	
	SDL_Rect playerRect = {(int)playerX, (int)playerY, 50, 50};
	SDL_SetRenderDrawColor(m_Renderer, 0, 150, 0, 200);	
	SDL_RenderFillRect(m_Renderer, &playerRect);
	//----------------------------

	SDL_RenderPresent(m_Renderer);
}

void Game::Destroy()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

SDL_Renderer* Game::GetRenderer()
{
	return m_Renderer;
}

SDL_Window* Game::GetWindow()
{
	return m_Window;
}

Game* Game::GetSingleton()
{
	if(s_Instance == NULL)
	{
		return s_Instance = new Game();
	}
	else
	{
		return s_Instance;
	}
}

bool Game::IsGameRunning()
{
	return m_isGameRunning;
}



