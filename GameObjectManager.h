#pragma once
class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void add(std::string objectName, VisibleGameObject* gameObjectToAdd);
	void remove(std::string objectName);
	
	int getObjectCount() const;
	VisibleGameObject* getObject(std::string name) const;
	
	
	void updateAll();
	void drawAll(sf::RenderWindow& window);
	
	float getDt();

private:
	std::map<std::string, VisibleGameObject*> _gameObjects;
	sf::Clock _objectsClock;


	struct GameObjectDeallocator {//making a function object- object that acts like a function
		void operator()(const std::pair<std::string, VisibleGameObject*> &p) const {
			delete p.second;//doesnt change the pair, only the guy pointed at by the second in the pair
		}
	};
};

