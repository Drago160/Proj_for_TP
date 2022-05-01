#pragma once
#include"Units.h"
#include<string>
#include"random.h"
#include"tools.h"
#include"find_nearest.h"

class Herbivor: virtual public Unit 
{
	public:
		Herbivor(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position);
		Herbivor(const Cord& my_position);
		void FindDirection(std::vector<Food*>& Food_list);
		void EatNear();
		void Update(std::vector<Food*>&);
		std::string GetClassName() const;
		Herbivor* Born();	
};
