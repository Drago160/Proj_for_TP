#include "Drawer.h"

#include "Food.h"
#include "herb.h"
#include "omni.h"
#include "pred.h"
#include "sfml.h"

void Drawer::DrawHerbivors(sf::RenderWindow& window,
                           const std::vector<Herbivor*>& herbivors) {
  for (const auto& h : herbivors) {
    window.draw(*(h->shape));
  }
}

void Drawer::DrawPredators(sf::RenderWindow& window,
                           const std::vector<Predator*>& predators) {
  for (const auto& h : predators) {
    window.draw(*(h->shape));
  }
}

void Drawer::DrawFood(sf::RenderWindow& window,
                      const std::vector<Food*>& foods) {
  for (const auto& f : foods) {
    window.draw(*(f->shape));
  }
}

void Drawer::DrawOmnivors(sf::RenderWindow& window,
                          const std::vector<Omnivor*>& omnivors) {
  for (const auto& omn : omnivors) {
    window.draw(*(omn->shape));
  }
}
