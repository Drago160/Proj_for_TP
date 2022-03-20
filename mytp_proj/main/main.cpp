#include<SFML/Graphics.hpp>
#include<iostream>
#include"herb.h"
#include<unistd.h>
#include<chrono>
#include<thread>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace sf;


void control(std::vector<CircleShape*> &shapes, std::vector<Herbivor*> &herbivors)
{
	for (int i = 0; i < herbivors.size(); i++)
	{
		if (herbivors[i]->GetEnergy()<=0)
		{
			herbivors[i]->Die();
			herbivors.erase(herbivors.begin() + i);
			delete shapes[i];
			shapes.erase(shapes.begin() + i);	
			continue;
		}  
		shapes[i]->setPosition(herbivors[i]->GetPosition().X, herbivors[i]->GetPosition().Y);

		if (herbivors[i]->GetEnergy() > 2 * ENERGY)
		{
			herbivors[i]->UpdateEnergy(-ENERGY);						    Herbivor* h = herbivors[i]->Born(); 
			herbivors.push_back(h);
			CircleShape *shape = new CircleShape(h->GetWeight()/5);
			shapes.push_back(shape);
			shape->setPosition(h->GetPosition().X, h->GetPosition().Y);
		}
			
	}
}


int main()
{
	int H = WINDOW_HEIGHT;
	int W = WINDOW_WEIGHT;

	RenderWindow window(VideoMode(H, W), "SIMULATION RUNS!!!");

	std::vector<Cord*> foods;
	std::vector<CircleShape*> foodshapes;
	Cord* f = new Cord(random(W), random(H));
	foods.push_back(f);



	std::vector<CircleShape*> shapes;
	CircleShape* shape1 = new CircleShape(WEIGHT/5);
	shapes.push_back(shape1);	


	Herbivor* h = new Herbivor(WEIGHT, SPEED, 10, {100, 100, 100}, {(int)(H/2), (int)(W/2)});

	std::vector<Herbivor*> herbivors;
	herbivors.push_back(h);

	shapes[0]->setPosition(herbivors[0]->GetPosition().X, herbivors[0]->GetPosition().Y);

	Clock clock;
	while (window.isOpen())
	{
		Event event;
        	while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed)
                	window.close();
        	}

		for(const auto& h: herbivors)
			h->FindDirection(foods);
		control(shapes, herbivors);
        	window.clear();
		for (const auto& i: shapes)
			window.draw(*i);
		for (const auto& i: foods)
		{
			CircleShape s(FOOD_SIZE, 8);
			s.setPosition(i->X, i->Y);
			s.setFillColor(Color::Red);
			window.draw(s);
		}

        		window.display();
			std::this_thread::sleep_for(std::chrono::milliseconds(SLIDES_PERIOD));
		if (clock.getElapsedTime().asMilliseconds() % FOOD_PERIOD == 0)
		{
			Cord* f = new Cord(random(H), random(W));
			foods.push_back(f);
		}
	}

	return 0;
}
