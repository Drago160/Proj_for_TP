#pragma once
#include"herb.h"

class Predator: public Unit 
{
	public:
		Predator(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position);
		void FindDirection(std::vector<Herbivor*>& Herb_list);
		void EatNear(const int&);
		void SetReducePower();
		Predator* Born();
	private:
		std::string classname;
};

