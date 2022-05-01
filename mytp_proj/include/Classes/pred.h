#pragma once
#include"herb.h"
#include"find_nearest_herb.h"


class Predator: virtual public Unit 
{
	public:
		Predator(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position);
		Predator(const Cord& my_position);
		void FindDirection(std::vector<Herbivor*>& Herb_list);
		void SetReducePower();
		void Update(std::vector<Herbivor*>&);
		Predator* Born();
};

