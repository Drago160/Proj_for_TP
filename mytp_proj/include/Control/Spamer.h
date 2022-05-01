#pragma once

#include"Food.h"
#include<vector>
#include"sfml.h"

class FoodSpamer
{
private:
	sf::Clock clock;
public:
	FoodSpamer(sf::Clock);	
	void update(std::vector<Food*>& foods);
};
