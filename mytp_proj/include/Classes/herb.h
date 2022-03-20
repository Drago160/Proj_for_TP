#include"Units.h"
#include<string>
class Herbivor: public Unit 
{
	public:
		Herbivor(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position);
		void FindDirection(std::vector<Cord*>& Food_list);
		void EatNear();
		std::string GetClassName() const;
		Herbivor* Born();	
	protected:
		std::string classname; 
};
