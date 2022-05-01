#pragma once
#include"sfml.h"
#include"herb.h"
#include"pred.h"
#include"omni.h"
#include"Food.h"

class Drawer
{
public:

	void DrawHerbivors(sf::RenderWindow&, const std::vector<Herbivor*>&);
	void DrawPredators(sf::RenderWindow&, const std::vector<Predator*>&);
	void DrawOmnivors(sf::RenderWindow&, const std::vector<Omnivor*>&);
	void DrawFood(sf::RenderWindow&, const std::vector<Food*>&);
};
