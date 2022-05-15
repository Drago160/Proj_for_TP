#pragma once
#include"herb.h"
#include"pred.h"
#include<vector>
#include"omni.h"

class Controller
{
public:
	void ControlHerb(std::vector<Herbivor*>&);
	void ControlPred(std::vector<Predator*>&);
	void ControlOmni(std::vector<Omnivor*>&);
};

