#include"sfml.h"
#include"about.h"
using namespace sf;
void menu(RenderWindow & window)
{
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground; 
	menuTexture1.loadFromFile("../img/play.png");
	menuTexture2.loadFromFile("../img/about.png");
	menuTexture3.loadFromFile("../img/exit.png");
//	aboutTexture.loadFromFile("../img/back.jpg");
	menuBackground.loadFromFile("../img/back.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
       	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 50);
	menu2.setPosition(100, 160);	
	menu3.setPosition(100, 270);	
	menuBg.setPosition(0, 0);


	


	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
  		{
   			if (event.type == Event::Closed)
			{
				window.close();
				isMenu = false;
			}
		}
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 50, 238, 69).contains(Mouse::getPosition(window))){ menu1.setColor(Color::Red); menuNum = 1; }
		if (IntRect(100, 160, 238, 69).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }
		if (IntRect(100, 270, 238, 69).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Red); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			if (menuNum == 2) { window.draw(about); window.display(); _about(window, isMenu);
			}
			if (menuNum == 3)  { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
	
}
