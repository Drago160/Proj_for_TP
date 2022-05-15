#pragma once
#include"sfml.h"
#include"herb.h"
#include"Food.h"
#include"pred.h"
#include"omni.h"
#include"SETTINGS.h"


class Game
{
public:
	sf::RenderWindow window;
	Game();
	void start();
	void Restart();
private:
	std::vector<Food*> foods;
	std::vector<Herbivor*> herbivors;
	std::vector<Predator*> predators;	
	std::vector<Omnivor*> omnivors;
};		
