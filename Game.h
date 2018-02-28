#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <iostream>
#include "PlayerPaddle.h"
#include "GameObjectManager.h"

//defult const and dtor. this static class runs the game
class Game
{
public:
	static void start();
	static const int SCREEN_WIDTH = 1024;
	static const int SCREEN_HEIGHT = 700;
	static sf::RenderWindow& getWindow() { return _mainWindow; };

private:
	
	enum GameState { UnInitiallized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static sf::Clock _gameClock;
	static GameObjectManager _gameObjectManager;

	static void showSplashScreen();
	static void showMenu();

	static bool isExiting();
	static void gameloop();
	
};

