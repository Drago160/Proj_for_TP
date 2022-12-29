#include "Food.h"

#include "SETTINGS.h"
#include "random.h"
#include "sfml.h"

Food::Food(int _x, int _y) {
  position = {_x, _y};
  shape = new sf::CircleShape(FOOD_SIZE, 8);
  shape->setPosition(_x, _y);
  shape->setFillColor(sf::Color(206, 255, 29));
}

Food::~Food() { delete shape; }
