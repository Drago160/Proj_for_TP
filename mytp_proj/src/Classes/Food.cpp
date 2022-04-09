#include"Food.h"
#include"SETTINGS.h"
#include"sfml.h"
#include"random.h"
Food::Food(const int& _x, const int& _y)
{
	x = _x;
	y = _y;
	shape = new sf::CircleShape(FOOD_SIZE, 8);
	shape->setPosition(x, y);
	shape->setFillColor(sf::Color(206, 255, 29));

}

Food::~Food()
{
	delete shape;
}
