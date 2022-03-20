#include"Units.h"

class Predator: public Unit {
	public:
		Predator(const int& weight, const int& speed, const int& variability, _Color my_color, Cord my_position)
		void find_direction();
		void eat_near();
		string get_class_name() const;
	private:
		string classname;
};

