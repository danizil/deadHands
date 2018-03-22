#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MenuResult MainMenu::show(sf::RenderWindow& window) {

	sf::Texture menuTexture;
	menuTexture.loadFromFile("images/mainmenu.png");
	sf::Sprite sprite(menuTexture);

	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 382 - 145;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.top = 383;
	exitButton.rect.height = 560 - 383;
	exitButton.action = Exit;

	_menuitems.push_back(playButton);
	_menuitems.push_back(exitButton);

	window.draw(sprite);
	window.display();
	//draws the menu screen and waits for user action
	return getMenuResponse(window);
}

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow& window) {

	sf::Event menuEvent;
	while (true) {
		while (window.pollEvent(menuEvent)) {
			
			if (menuEvent.type == sf::Event::MouseButtonPressed) {
				return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}

			if (menuEvent.type == sf::Event::Closed
			  ||menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Q) {
				return Exit;
			}

		}
	}
}
	
MainMenu::MenuResult MainMenu::handleClick(int x, int y) {
	std::list<MenuItem>::iterator it;
	for (it = _menuitems.begin(); it != _menuitems.end(); it++) {
		sf::Rect<int> itemRect = it->rect;
		if (   itemRect.top < y
			&& itemRect.top + itemRect.height > y
			&& itemRect.left < x
			&& itemRect.left + itemRect.width > x) {
			return it->action;
		}
	}
	return Nothing;
}

