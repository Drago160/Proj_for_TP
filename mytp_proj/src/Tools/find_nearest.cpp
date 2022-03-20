#include<cmath>
#include"tools.h"
using namespace std;
int find_nearest(const Cord& self_pos, const vector<Cord*>& Foods, const int& vision_Radius)
{
	int ret = -1;
	int min = pow(vision_Radius, 2);
	int x, y;
	for(int i = 0; i < Foods.size(); i++)
	{
		x = Foods[i]->X;
		y = Foods[i]->Y;
		if (pow(x - self_pos.X, 2) + pow(y - self_pos.Y, 2) < min)
		{
			min = pow(x - self_pos.X, 2) + pow(y - self_pos.Y, 2);
			ret = i;
		}	
	}
	return ret;	
}
