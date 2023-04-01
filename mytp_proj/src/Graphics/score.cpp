#include "score.h"

//Рисуем статистику (добавляя число)
void score(sf::RenderWindow& window, const std::string str, sf::Text& text, int n) {
  std::ostringstream score;
  score << n;
  text.setString(str + score.str());
  window.draw(text);
}
