#include"random.h"
#include"tools.h"
#include"herb.h"
#include"pred.h"
#include"find_nearest_herb.h"
#include<cmath>
#include<iostream>


Predator::Predator(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position):Unit(my_weight, my_speed, my_variability, my_color, my_position)
{
        classname = "predator";
	      reduce_power *= REDUCE_PRED_KOOF;
}


void Predator::FindDirection(std::vector<Herbivor*>& Herb_list)
{

        int num_of_nearest = find_nearest_herb(position, Herb_list, weight*5);
        if (num_of_nearest == -1)
        {
 		direction = {0, 0};
                UpdateEnergy(-reduce_power);
                return;
        }

        Herbivor* nearest_herb = Herb_list[num_of_nearest];


        if (pow(nearest_herb->GetPosition().X - position.X, 2) + pow(nearest_herb->GetPosition().Y - position.Y, 2) < pow(weight/6, 2))
        {
		int E = nearest_herb->GetEnergy();
                Herb_list.erase(Herb_list.begin()+num_of_nearest);
                delete nearest_herb;	
               	UpdateEnergy(E);
		direction = {0, 0};
                FindDirection(Herb_list);
                return;
        }

        float r = sqrt(pow(nearest_herb->GetPosition().X - position.X, 2) + pow(nearest_herb->GetPosition().Y - position.Y, 2));
        float x = nearest_herb->GetPosition().X - position.X;
        float y = nearest_herb->GetPosition().Y - position.Y;
        direction = {x/r, y/r};
        Step();
}

Predator* Predator:: Born()
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
        Predator* h = new Predator(w, v, var, Col, {x, y});
        return h;
}
