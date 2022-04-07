#include"random.h"
#include"herb.h"
#include"Food.h"
#include<cmath>
#include<iostream>


Herbivor::Herbivor(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position):Unit(my_weight, my_speed, my_variability, my_color, my_position)
{
	classname = "herbivor";
}

void Herbivor::FindDirection(std::vector<Food*>& Food_list)
{
	int num_of_nearest = find_nearest_food(position, Food_list, weight*6);
	if (num_of_nearest == -1)
	{
		direction = {0, 0};
		UpdateEnergy(-reduce_power);	
		return;
	}
	Food* nearest_food = Food_list[num_of_nearest];
	

	if (pow(nearest_food->x - position.X, 2) + pow(nearest_food->y - position.Y, 2) < pow(weight/6, 2))
	{
		Food_list.erase(Food_list.begin()+num_of_nearest);
		delete nearest_food;
		EatNear();
		direction = {0, 0};
		FindDirection(Food_list);
		return;
	}

	float r = sqrt(pow(nearest_food->x - position.X, 2) + pow(nearest_food->y - position.Y, 2));	
	float x = nearest_food->x - position.X;
	float y = nearest_food->y - position.Y;
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
	_Color Col = {color.R, color.G, color.B};
	int v = distrebute(speed, (int)(variability/4));
	int w = distrebute(weight, variability);
	int x = Disp(position.X, weight/5 + w/5);
	int y = position.Y + randSign() * sqrt(pow(weight/5 + w/5, 2) - pow((position.X - x), 2));
	int var = variability;
	if (rand_bool(10))
	{
		var = distrebute(var, 1);
	}
	v = Maxmin(v, 100, 10);
	w = Maxmin(w, 300, 12);
	var = Maxmin(var, 12, 1);
	//std::cout<<w<<std::endl;
	Herbivor* h = new Herbivor(w, v, var, Col, {x, y});
	return h;
}
