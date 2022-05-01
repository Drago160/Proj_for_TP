#include"SETTINGS.h"
#include"random.h"
#include"Spamer.h"

FoodSpamer::FoodSpamer(sf::Clock my_clock)
{
	clock = my_clock;
}

void FoodSpamer::update(std::vector<Food*>& foods)
{
                if (clock.getElapsedTime().asMilliseconds() % FOOD_PERIOD == 0)
		{
                        for(int i = 0; i < FOOD_AMOUNT; i++)
			{
                                foods.push_back(new Food(random(WINDOW_WEIGHT), random(WINDOW_HEIGHT)));
			}

                }
}
