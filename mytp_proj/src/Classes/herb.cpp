#include"random.h"
#include"herb.h"
#include<cmath>
#include<iostream>
#include"math_function.h"
#include<string>

Herbivor::Herbivor(const Cord& my_position):Unit("herbivor", my_position)
{
	reduce_power *= REDUCE_HERB_KOOF;
}


Herbivor::Herbivor(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position):Unit(my_weight, my_speed, my_variability, my_color, my_position)
{
	reduce_power *= REDUCE_HERB_KOOF;
}

void Herbivor::FindDirection(std::vector<Food*>& Food_list)
{
	int num_of_nearest = find_nearest_food(position, Food_list, weight*6);
	//-1 - флаг того что не найдет ближний
	if (num_of_nearest == -1)
	{
		direction = {0, 0};
		return;
	}
	Food* nearest_food = Food_list[num_of_nearest];
	
	int sqDist = sqDistance(position, nearest_food->position);
	if (sqDist < pow(weight/5, 2)) 
	{
		Food_list.erase(Food_list.begin()+num_of_nearest);
		delete nearest_food;
		EatNear();
		direction = {0, 0};
		FindDirection(Food_list);
		return;
	}
	float r = sqrt(sqDist);	
	float x = nearest_food->position.X - position.X;
	float y = nearest_food->position.Y - position.Y;
	struct Direction d = {x/r, y/r};
	direction = d;//Round_to(direction, d, 1);
}

void Herbivor:: Update(std::vector<Food*>& foods)
{
	FindDirection(foods);
	Step();
}

void Herbivor:: EatNear()
{
	UpdateEnergy(FOOD_COST);
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
	Herbivor* h = new Herbivor(w, v, var, Col, {x, y});
	return h;
}
