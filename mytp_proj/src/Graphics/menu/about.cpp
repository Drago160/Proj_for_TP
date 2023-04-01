#include "about.h"

#include "SETTINGS.h"

//Рисуем окно about
void _about(sf::RenderWindow& window, bool& isMenu) {
  sf::Font font;
  font.loadFromFile(ABOUT_FONT_PATH);
  sf::Text text("", font, ABOUT_FONT_SIZE);
  text.setFillColor(sf::Color::Black);
  text.setPosition(ABOUT_TEXT_POSITION_X, ABOUT_TEXT_POSITION_Y);
  text.setString(ABOUT_INFO);

  while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && isMenu) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        isMenu = false;
      }
    }
    window.draw(text);
    window.display();
  }
}
