#pragma once
#include"Game.h"
#include"sfml.h"
#include<iostream>
#include<sstream>
void score(sf::RenderWindow& window, const std::string str, sf::Text& text, int n)
{
	std::ostringstream score;
	score << n;
	text.setString(str + score.str());	
	window.draw(text);
}
