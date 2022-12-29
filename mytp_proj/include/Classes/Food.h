#pragma once
#include"sfml.h"
#include"tools.h"

class Food
{
public:
	Food(int, int);
	sf::CircleShape* shape;
	Cord position;	
	~Food();	
};
