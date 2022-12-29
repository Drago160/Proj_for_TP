#include "Controller.h"

void Controller::ControlHerb(std::vector<Herbivor*>& herbivors) {
  for (int i = 0; i < herbivors.size(); i++) {
    if (herbivors[i]->GetEnergy() <= 0) {
      delete herbivors[i];
      herbivors.erase(herbivors.begin() + i);
      continue;
    }

    if (herbivors[i]->GetEnergy() > 2 * ENERGY) {
      herbivors[i]->UpdateEnergy(-ENERGY);
      Herbivor* h = herbivors[i]->Born();
      herbivors.push_back(h);
    }
  }
}

void Controller::ControlPred(std::vector<Predator*>& predators) {
  for (int i = 0; i < predators.size(); i++) {
    if (predators[i]->GetEnergy() <= 0) {
      delete predators[i];
      predators.erase(predators.begin() + i);
      continue;
    }

    if (predators[i]->GetEnergy() > 2 * ENERGY) {
      predators[i]->UpdateEnergy(-ENERGY);
      Predator* h = predators[i]->Born();
      predators.push_back(h);
    }
  }
}

void Controller::ControlOmni(std::vector<Omnivor*>& omnivors) {
  for (int i = 0; i < omnivors.size(); i++) {
    if (omnivors[i]->GetEnergy() <= 0) {
      delete omnivors[i];
      omnivors.erase(omnivors.begin() + i);
      continue;
    }

    if (omnivors[i]->GetEnergy() > 2 * ENERGY) {
      omnivors[i]->UpdateEnergy(-ENERGY);
      Omnivor* h = omnivors[i]->Born();
      omnivors.push_back(h);
    }
  }
}
