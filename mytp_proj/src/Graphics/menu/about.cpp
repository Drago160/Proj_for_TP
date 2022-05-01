#include"about.h"

//Рисуем окно about
void _about(sf::RenderWindow& window, bool& isMenu)
{
	sf::Font font;
	font.loadFromFile("../fonts/main_font.ttf");
	sf::Text text("", font, 40);
	text.setFillColor(sf::Color::Black);
	text.setPosition(100, 100);
	text.setString
	(
		"Click ESC to return into main menu\nYou can create new Herbivors(LMB) and Predators(RMB)\nThe main goal is to create stable system\nMB it is Impossible\nHave a nice game"
	);
	
	while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && isMenu)
	{	
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
				isMenu = false;	
			}
		}
		window.draw(text);
		window.display();
	}
}
