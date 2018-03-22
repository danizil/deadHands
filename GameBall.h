#pragma once
class GameBall: public VisibleGameObject
{
public:
	GameBall();
	virtual ~GameBall();
	
	void updatePosition(float elapsedTime);
	void setVelocity(sf::Vector2f);
	
	sf::Vector2f getVelocity() const;
	sf::Vector2f getPosition() const;

private:

	sf::Vector2f _velocity;
};

