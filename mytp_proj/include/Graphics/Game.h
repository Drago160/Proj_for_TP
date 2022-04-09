#pragma once
#include"sfml.h"
#include"herb.h"
#include"Food.h"
#include"pred.h"
#include"SETTINGS.h"

void control(std::vector<Herbivor*> &herbivors);
void control_pred(std::vector<Predator*>& predators);


/*
sf::Font font;
font.loadFromFile("../fonts/main_font.ttf");
sf::Text herb_score;//("", font, 20);
sf::Text pred_score;//("", font, 20); 
herb_score.setColor(sf::Color::Blue);
pred_score.setColor(sf::Color::Red);                                
herb_score.setString("Herbivors: ");
pred_score.setString("Predators: ");
herb_score.setPosition(WINDOW_WIDTH - 100, WINDOW_WEIGHT - 100);
*/

class Game
{
public:
	sf::RenderWindow window;
	Game();
	void start();
	std::vector<Food*> foods;
	std::vector<Herbivor*> herbivors;
	std::vector<Predator*> predators;	
};		
