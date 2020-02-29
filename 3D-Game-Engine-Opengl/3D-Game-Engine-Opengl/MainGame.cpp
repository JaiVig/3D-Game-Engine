#include "MainGame.h"
#include<string>
#include<iostream>
void fatalerror(std::string error)
{
	std::cout << error << std::endl;
	std::cout << "enter any to quit" << std::endl;
	int a;
	std::cin >> a;
	SDL_QUIT;
}
MainGame::MainGame()
{
	_window = nullptr;
	_ScreenHeight = 600;
	_ScreenWidth = 600;
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void MainGame::Run()
{
	InitSystems();
	GameLoop();
}
void MainGame::GameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		ProcessInput();
	}
}


void MainGame::ProcessInput()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		
		}
	}
}



void MainGame::InitSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,_ScreenWidth,_ScreenHeight, SDL_WINDOW_OPENGL);
	if (_window == nullptr)
	{
		fatalerror("Couldnt create sdl window");
	}

	SDL_GLContext context = SDL_GL_CreateContext(_window);

	if (context == nullptr)
	{
		fatalerror("Couldnt create SDL_GLcontext");
	}

	GLenum err = glewInit();

	if (err != GLEW_OK)
	{
		fatalerror("Couldnt init Glew");
	}
}


void MainGame::DrawGame()
{

}
