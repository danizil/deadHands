#pragma once
#include "VisibleGameObject.h"
class PlayerPaddle :
	public VisibleGameObject
{
public:

	PlayerPaddle();
	~PlayerPaddle();
	
	void getUserInput();
	void updatePosition(float elapsedTime);
	//void draw(sf::RenderWindow& window);
	
	sf::Vector2f getVelocity() const;
	void setVelocity(sf::Vector2f v);

private:

	sf::Vector2f _velocity;
};

