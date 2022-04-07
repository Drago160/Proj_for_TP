#pragma once
#include"sfml.h"
#include"herb.h"
#include"Food.h"
#include"pred.h"
void control(std::vector<Herbivor*> &herbivors);
void control_pred(std::vector<Predator*>& predators);

class Game
{
public:
	sf::RenderWindow window;
	Game();
	void start();
	std::vector<Food*> foods;
	std::vector<Herbivor*> herbivors;
	std::vector<Predator*> predators;	
};		
