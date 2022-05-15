#pragma once
#include"herb.h"
#include"pred.h"
#include"Food.h"
#include"omni.h"

class Updater
{
public:
	void UpdateHerb(const std::vector<Herbivor*>&, std::vector<Food*>&);
	void UpdatePred(const std::vector<Predator*>&, std::vector<Herbivor*>&);
	void UpdateOmni(const std::vector<Omnivor*>&, std::vector<Food*>&, std::vector<Herbivor*>&);
};
