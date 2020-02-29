#pragma once
#include<SDL.h>
#include<GL\glew.h>

enum class GameState{PLAY,EXIT};
class MainGame
{
public:
	MainGame();
	~MainGame();
	void Run(); 
	void InitSystems(); //init libs and create window
	void ProcessInput();
	void GameLoop();//gameloop
	void DrawGame();
private:
	SDL_Window* _window;
	int _ScreenWidth;
	int _ScreenHeight;
	GameState _gameState;
};

