#include"herb.h"
#include"find_nearest_herb.h"
#include"math_function.h"
#include"tools.h"
#include<cmath>
int find_nearest_herb(const Cord& self_pos, const std::vector<Herbivor*>& Herbs, const int& vision_Radius)
{
        int ret = -1;
        int min = pow(vision_Radius, 2);
        int x, y;
	int sqDist;
        for(int i = 0; i < Herbs.size(); i++)
        {
                x = Herbs[i]->GetPosition().X;
                y = Herbs[i]->GetPosition().Y;
		sqDist = sqDistance(Herbs[i]->GetPosition(), self_pos);
                if (sqDist < min)//(pow(x - self_pos.X, 2) + pow(y - self_pos.Y, 2) < min)
                {
                        min = sqDist;
                        ret = i;
                }
        }
        return ret;
}
