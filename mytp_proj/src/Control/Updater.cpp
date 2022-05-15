#include"Updater.h"

void Updater::UpdateHerb(const std::vector<Herbivor*>& herbivors, std::vector<Food*>& foods)
{
	for(const auto& h: herbivors)
		h->Update(foods);
}

void Updater::UpdatePred(const std::vector<Predator*>& predators, std::vector<Herbivor*>& herbivors)
{
	for(const auto& p: predators)
		p->Update(herbivors);
}

void Updater::UpdateOmni(const std::vector<Omnivor*>& omnivors, std::vector<Food*>& foods, std::vector<Herbivor*>& herbivors)
{
	for(const auto& omn: omnivors)
		omn->Update(foods, herbivors);
}
