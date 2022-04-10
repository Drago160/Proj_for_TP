#include"tools.h"
#include"sfml.h"
#include"random.h"

class Unit
{
	public:
		Unit(const int& weight, const int& speed, const int& variability,const _Color& my_color,const Cord& my_position);
		int GetWeight() const;
		void SetEnergy();
		int GetEnergy() const;
		void SetPosition(const Cord& my_position);
		Cord GetPosition() const;
		void UpdateEnergy(const int& delta);
		void SetReducePower();
		void Die();
		void Step();	
		~Unit();
	protected:
		int weight = WEIGHT;
		int speed = SPEED;
		_Color color;
		int energy = ENERGY;
		Direction direction = {0, 0};
		int reduce_power;
		Cord position = {-100, -100};
		int variability;
	public:
		sf::CircleShape* shape;
};
