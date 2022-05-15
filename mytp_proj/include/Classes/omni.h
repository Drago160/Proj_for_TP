#pragma once
#include"herb.h"
#include"pred.h"
#include"Food.h"


class Omnivor:public Predator, public Herbivor 
{
        public:
                Omnivor(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position);
		Omnivor(const Cord& my_position);
                void FindDirection(std::vector<Food*>&, std::vector<Herbivor*>&);
                void Update(std::vector<Food*>&, std::vector<Herbivor*>&);
                Omnivor* Born();
};
