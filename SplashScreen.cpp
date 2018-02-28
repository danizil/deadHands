#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow& window) {
	sf::Texture splashTexture;
	if (!splashTexture.loadFromFile("images/SplashScreen.png")) {
		return;
	}
	
	sf::Sprite sproit(splashTexture);
	window.draw(sproit);
	window.display();

	sf::Event evento;
	while (true) {
		while (window.pollEvent(evento)) {
			if (evento.type == sf::Event::EventType::KeyPressed
				|| evento.type == sf::Event::EventType::MouseButtonPressed
				|| evento.type == sf::Event::EventType::Closed) {
				
				return;
			}
		}
	}
}