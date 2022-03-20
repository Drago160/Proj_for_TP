#include"Units.h"


class Omnivor: public Predator, public Herbivor
{
	public:
		Omnivor(const int& weight, const int& speed, const int& variability, Color my_color, Cord my_position, const int& my_gen)
		void find_direction();
		void eat_near();
	private:
		int predator_gen;
		string classname;
};
