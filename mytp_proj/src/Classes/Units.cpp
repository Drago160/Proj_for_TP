#include"random.h"
#include"Units.h"
#include<iostream>

Unit::Unit(const std::string& classname, const Cord& my_position)
{
	int R, G, B;
	if (classname == "herbivor")
	{
		R = H_R;
		G = H_G;
		B = H_B;
	}
	else 
	if (classname == "predator")
	{
		R = P_R;
		G = P_G;
		B = P_B;
	}
	else
	if (classname == "omnivor")
	{
		R = O_R;
		G = O_G;
		B = O_B; 
	}
	weight = WEIGHT;
	speed = SPEED;
	color = {R, G, B};
	variability = VARIABILITY;
	position = my_position;
	SetEnergy();
	SetReducePower();
	shape = new sf::CircleShape(weight/5);
	shape->setPosition(position.X - weight/10, position.Y - weight/10);
	shape->setFillColor(sf::Color(color.R, color.G, color.B));
}

Unit::Unit(const int& my_weight, const int& my_speed, const int& my_variability, const _Color& my_color, const Cord& my_position)
{
	weight = my_weight;
	speed = my_speed;
	color = my_color;
	variability = my_variability;
	position = my_position;
	SetEnergy();
	SetReducePower();
	shape = new sf::CircleShape(weight/5);
	shape->setPosition(position.X - weight/10, position.Y - weight/10);
	shape->setFillColor(sf::Color(color.R, color.G, color.B));
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
	reduce_power = (int)(weight * (speed * speed)* ENERGY_KOOF);	
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
	int dX = (int)speed*0.2*direction.X;
	int dY = (int)speed*0.2*direction.Y;
	position = {position.X + dX, position.Y + dY};
	energy -= reduce_power;
	shape->setPosition(position.X - weight/10, position.Y - weight/10);
}


Unit::~Unit()
{
	delete shape;
}
