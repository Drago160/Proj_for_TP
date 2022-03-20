#include<string>
#include<vector>
#include"SETTINGS.h"
#include"random.h"
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


int find_nearest(const Cord& self_pos, const std::vector<Cord*>&, const int& vision_Radius);

