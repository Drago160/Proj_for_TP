#include"Game.h"
#include"score.h"
#include"sfml.h"
#include"menu.h"
#include"SETTINGS.h"
#include<unistd.h>
#include<chrono>
#include<thread>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include"pred.h"
#include<iostream>
#include<sstream>

void control(std::vector<Herbivor*> &herbivors)
{
	for (int i = 0; i < herbivors.size(); i++)
	{
		if (herbivors[i]->GetEnergy() <= 0)
		{
			delete herbivors[i];
			herbivors.erase(herbivors.begin() + i);
			continue;
		}  

		if (herbivors[i]->GetEnergy() > 2 * ENERGY)
		{
			herbivors[i]->UpdateEnergy(-ENERGY);
			Herbivor* h = herbivors[i]->Born(); 
			herbivors.push_back(h);
		}
			
	}
}
void control_pred(std::vector<Predator*>& predators)
{
	for (int i = 0; i < predators.size(); i++)
	{
		if (predators[i]->GetEnergy() <= 0)
		{
			delete predators[i];
			predators.erase(predators.begin() + i);
			continue;
		}  

		if (predators[i]->GetEnergy() > 2 * ENERGY)
		{
			predators[i]->UpdateEnergy(-ENERGY);
			Predator* h = predators[i]->Born(); 
			predators.push_back(h);
		}
			
	}
}

Game::Game()
{
	window.create(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WEIGHT), "SIMULATION RUNS!!!");
	window.setFramerateLimit(60);
}

void Game::start()
{

	sf::Clock clock;

       	Herbivor* h = new Herbivor(WEIGHT, SPEED, 6, {0, 155, 255}, {(int)(WINDOW_HEIGHT/1), (int)(WINDOW_WEIGHT/1)});

	Predator* q = new Predator(WEIGHT, SPEED, 6, {250, 0, 0}, {(int)(WINDOW_HEIGHT/4), (int)(WINDOW_WEIGHT/4)});
	predators.push_back(q);
	herbivors.push_back(h);

	menu(window);	
	
	sf::Font font;
	font.loadFromFile("../fonts/main_font.ttf");
	sf::Text text1("", font, 30);
	sf::Text text2("", font, 30);
	text1.setFillColor(sf::Color::Blue);
	text2.setFillColor(sf::Color::Red);
	text1.setPosition(WINDOW_HEIGHT - 200, 50);
	text2.setPosition(WINDOW_HEIGHT - 200, 80);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
					menu(window);

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					int x = event.mouseButton.x;
					int y = event.mouseButton.y;
					Predator* w = new Predator(WEIGHT, SPEED, 6, {250, 0, 0}, {(int)(x), (int)(y)});
					predators.push_back(w);
				}

				if (event.mouseButton.button == sf::Mouse::Left)
				{
					int x = event.mouseButton.x;
					int y = event.mouseButton.y;
					Herbivor* e = new Herbivor(WEIGHT, SPEED, 6, {0, 155, 255}, {(int)(x), (int)(y)});
					herbivors.push_back(e);
				}
			}
		}

		window.clear(sf::Color(211, 211, 211));
		
		for(const auto& h: herbivors)
		{
			h->FindDirection(foods);	
		}

		for(const auto& p: predators)
		{
			p->FindDirection(herbivors);	
		}
		
		control(herbivors);
		control_pred(predators);

		for(const auto& h: herbivors)
		{
			window.draw(*(h->shape));	
		}
		for(const auto& p: predators)
		{
			window.draw(*(p->shape));	
		}

		for(const auto& f: foods)
		{
			window.draw(*(f->shape));
		}



		score(window, "herbivors: ", text1, herbivors.size());		
		score(window, "predators: ", text2, predators.size());



		window.display();

		std::this_thread::sleep_for(std::chrono::milliseconds(SLIDES_PERIOD));
		if (clock.getElapsedTime().asMilliseconds() % FOOD_PERIOD == 0)
		{
			for(int i = 0; i < FOOD_AMOUNT; i++)
			{	
				foods.push_back(new Food(random(WINDOW_HEIGHT), random(WINDOW_WEIGHT)));
			}
			
		}
	}
}
