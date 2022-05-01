#include"random.h"
#include"herb.h"
#include"pred.h"
#include"omni.h"
#include<cmath>
#include<iostream>
#include"math_function.h"

Omnivor::Omnivor(const Cord& my_position):Unit("omnivor", my_position), Predator(my_position), Herbivor(my_position)
{
	reduce_power *= REDUCE_OMNI_KOOF;	
}


Omnivor::Omnivor(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position):Unit(my_weight, my_speed, my_variability, my_color, my_position), Predator(my_position), Herbivor(my_position)
{
	reduce_power *= REDUCE_OMNI_KOOF;	
}

void Omnivor::FindDirection(std::vector<Food*>& Food_list, std::vector<Herbivor*>& Herb_list)
{

        int num_of_nearest_herb = find_nearest_herb(position, Herb_list, weight*5);
	int num_of_nearest_food = find_nearest_food(position, Food_list, weight*5);

        if (num_of_nearest_herb == -1 && num_of_nearest_food == -1)
        {
                direction = {0, 0};
                return;
        }

	if(num_of_nearest_herb != -1 && num_of_nearest_food != -1)
	{
		Food* nearest_food = Food_list[num_of_nearest_food];
	       	Herbivor* nearest_herb = Herb_list[num_of_nearest_herb];	
	
		int food_dist = sqDistance(nearest_food->position, position);
		int herb_dist = sqDistance(nearest_herb->GetPosition(), position); 

		if (herb_dist < food_dist)
			num_of_nearest_food = -1;
		else
			num_of_nearest_herb = -1;
			
	}

	if (num_of_nearest_herb == -1)
		Herbivor::FindDirection(Food_list);
	else
		Predator::FindDirection(Herb_list);
}

void Omnivor::Update(std::vector<Food*>& foods, std::vector<Herbivor*>& herbivors)
{
	FindDirection(foods, herbivors);
	Step();
}


Omnivor* Omnivor:: Born()
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
        Omnivor* omn = new Omnivor(w, v, var, Col, {x, y});
        return omn;
}
