#include "stdafx.h"
#include "Game.h"
#include "VisibleGameObject.h"
#include "PlayerPaddle.h"

void Game::start()
{
	if (_gameState == UnInitiallized) {
		return;
	}

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pangale");
	PlayerPaddle* player1 = new PlayerPaddle;
	player1->load("images/paddle.png");
	player1->setPosition(1024 / 2 - 45, 650);

	_gameObjectManager.add("player1", player1);
	
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
			
			//Sleep(10);
			_gameObjectManager.updateAll();
			_gameObjectManager.drawAll(_mainWindow);
			_mainWindow.display();
			_mainWindow.clear(sf::Color::Green);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) showMenu();
	
			
			sf::Event currentEvent;
			if(_mainWindow.pollEvent(currentEvent)){
				while (_mainWindow.pollEvent(currentEvent)) { //might be a prob here
				
				
				
					//_gameObjectManager.updateAll();
					//_gameObjectManager.drawAll(_mainWindow);
					//_mainWindow.display();

					if (currentEvent.type == sf::Event::Closed) _gameState = Exiting;
				
					if (currentEvent.type == sf::Event::KeyPressed) {
						if (currentEvent.key.code == sf::Keyboard::Escape) showMenu();
						
						
						
					}


				}
	
			
			}
			/*
			else {
				Sleep(10);
				_gameObjectManager.updateAll();
				_gameObjectManager.drawAll(_mainWindow);
				_mainWindow.display();
				_mainWindow.clear(sf::Color::Green);
			}
			*/
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


}


Game::GameState Game::_gameState = Playing;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
sf::Clock Game::_gameClock;