#include"Units.h"

Unit::Unit(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position)
{
	weight = my_weight;
	speed = my_speed;
	color = my_color;
	position = my_position;
	SetEnergy();
	SetReducePower();
}

int Unit::GetWeight() const
{
	return weight;
}

void Unit::SetEnergy()
{
	energy = ENERGY;
}

int Unit::GetEnergy() const
{
	return energy;
}

void Unit::SetPosition(const Cord& my_position)
{
	position = my_position;
}

Cord Unit::GetPosition() const
{
	return position;
}

void Unit::SetReducePower()
{
	reduce_power = (int)(weight * (speed * speed)* ENERGY_KOOF) ;	
}

void Unit::UpdateEnergy(const int& delta)
{
	energy += delta;	
}

void Unit::Die()
{
	delete this;
}

void Unit::Step()
{
	position = {(int)(position.X + speed*0.2*direction.X), (int)(position.Y + speed*0.2*direction.Y)};
	energy -= reduce_power;
}

