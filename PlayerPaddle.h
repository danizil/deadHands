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

	float getVelocity() const;
	void setVelocity(float v);

private:
	float _velocity;

};

