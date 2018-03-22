#pragma once

class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void load(std::string fileName);
	virtual void draw(sf::RenderWindow& window);
	virtual void updatePosition(float elapsedTime) = 0; //might be a prob with objects without the func
	
	virtual void getUserInput(){}

	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition() const;
	virtual sf::Vector2f getOrigin() const;

	virtual bool inDomain(VisibleGameObject& another) {
		float angle = _sprite.getRotation();
		unsigned int width = _sprite.getTexture()->getSize().x;
		unsigned int hight = _sprite.getTexture()->getSize().y;
		//sf::Vector2f u(width*cos(angle), width*sin(angle)), v(hight*cos(3.14/2 - angle))  ;
		return true;
	}

	virtual bool isLoaded();

	struct Rect {
		Rect(sf::Vector2f meas);
		Rect() {};
		sf::Vector2f _position;
		sf::Vector2f _measurements;
		float _angle;
		bool inDomain(float x, float y);
	};

protected:
	sf::Sprite& getSprite();
	sf::Sprite _sprite;
	Rect _rect;

private:
	
	sf::Texture _texture;
	std::string _filename;
	bool _isLoaded;
};

