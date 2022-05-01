#pragma once

#include<string>
#include<vector>
#include"SETTINGS.h"
#include"random.h"
#include<cmath>

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


struct Direction Round_to(struct Direction, struct Direction, float delta);

struct Cord
{
	int X;
	int Y;
};

int Maxmin(const int& N, const int& M, const int& m);
