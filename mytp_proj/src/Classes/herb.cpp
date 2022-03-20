#include"herb.h"
#include<cmath>
#include<iostream>
Herbivor::Herbivor(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position):Unit(my_weight, my_speed, my_variability, my_color, my_position)
{
	classname = "herbivor";
}

void Herbivor::FindDirection(std::vector<Cord*>& Food_list)
{
	int num_of_nearest = find_nearest(position, Food_list, weight*6);
	
	if (num_of_nearest == -1)
	{
		direction = {0, 0};
		UpdateEnergy(-reduce_power);	
		return;
	}
	Cord* nearest_food = Food_list[num_of_nearest];
	if (pow(nearest_food->X - position.X, 2) + pow(nearest_food->Y - position.Y, 2) < pow(weight/5, 2))
	{
		Food_list.erase(Food_list.begin()+num_of_nearest);
		delete nearest_food;
		EatNear();
		UpdateEnergy(-reduce_power);
		direction = {0, 0};
		return;
	}

	float r = sqrt(pow(nearest_food->X - position.X, 2) + pow(nearest_food->Y - position.Y, 2));	
	float x = nearest_food->X - position.X;
	float y = nearest_food->Y - position.Y;
	direction = {x/r, y/r};
	Step();
}
void Herbivor:: EatNear()
{
	UpdateEnergy(FOOD_COST);
}

std::string Herbivor::GetClassName() const
{
	return classname;
}

Herbivor* Herbivor:: Born()
{
	int w = std::max(15, Disp(weight, variability));
	int x = Disp(position.X, weight/5 + w/5);
	int y = position.Y + randSign() * sqrt(pow(weight/5 + w/5, 2) - pow((position.X - x), 2));
	int v = std::max(Disp(speed, variability/2), 8);
	Herbivor* h = new Herbivor(w, v, 10, {0, 0, 0}, {x, y});
	return h;
}
