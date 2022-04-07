#pragma once
#include<string>
#include<vector>
#include"SETTINGS.h"
#include"random.h"
#include"Food.h"

struct _Color
{
	int R;
	int G;
	int B;
};

struct Direction
{
	float X;
	float Y;
};

class Cord
{
	public:
		Cord(int x, int y)
		{
			X = x;
			Y = y;
		}
		int X;
		int Y;
};

/*
int find_nearest_food(const Cord& self_pos, const std::vector<Food*>&, const int& vision_Radius);

int find_nearest_herb(const Cord& self_pos, const std::vector<Herbivor*>&, const int vision_Radius)
*/


int Maxmin(const int& N, const int& M, const int& m);
