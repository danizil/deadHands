#include "stdafx.h"
#include "Game.h"
#include "VisibleGameObject.h"
#include "PlayerPaddle.h"
#include "GameBall.h"


void Game::start()
{
	if (_gameState == UnInitiallized) {
		return;
	}

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pangale");
	
	PlayerPaddle* player1 = new PlayerPaddle;
	//player1->load("images/paddle.png");
	player1->setPosition(512, 350);

	GameBall* theBall = new GameBall;
	theBall->setPosition(530, 370);

	_gameObjectManager.add("player1", player1);
	_gameObjectManager.add("ball", theBall);

	_gameState = ShowingSplash;

	while (!isExiting()) {
		gameloop();
	}
	_mainWindow.close();
}

bool Game::isExiting() {
	if (_gameState == Exiting) {
		return true;
	}
	return false;
}

void Game::gameloop() {
	switch (_gameState) {
		case Game::Playing:
		{
			_gameObjectManager.getObject("player1")->getUserInput();
			_gameObjectManager.updateAll();
			_gameObjectManager.drawAll(_mainWindow);
			_mainWindow.display();
			_mainWindow.clear(sf::Color::Green);
			
	
			
			sf::Event currentEvent;

			while (_mainWindow.pollEvent(currentEvent)) { //might be a prob here
				
				switch (currentEvent.type) {
					
					case sf::Event::Closed: {
						_gameState = Exiting;
					}
					case sf::Event::KeyPressed: {
						
					}
					
				}
				
				if (currentEvent.type == sf::Event::KeyPressed) {
					if (currentEvent.key.code == sf::Keyboard::Escape) showMenu();
						
						
						
				}


			}
	
			
			
			break;
		}
		case Game::ShowingSplash:
		{
			showSplashScreen();
			_gameState = Game::ShowingMenu;
			break;

		}
		case Game::ShowingMenu:
		{
			showMenu();
		}
	}
	
}

void Game::showSplashScreen() {
	SplashScreen splashscreen;
	splashscreen.show(_mainWindow);
	_gameState = Game::ShowingSplash;
}



void Game::showMenu() {
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.show(_mainWindow);
	switch (result) {
	case MainMenu::Play:
		_gameState = Playing;
		break;
		
	case MainMenu::Exit:
		_gameState = Exiting;
		break;
	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		_gameState = Exiting;
	}
}


Game::GameState Game::_gameState = Playing;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
sf::Clock Game::_gameClock;