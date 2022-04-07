#pragma once
#include"sfml.h"
class Food
{
	public:
		Food(const int&, const int&);
		sf::CircleShape* shape;
		int x;
		int y;
		~Food();	

};
