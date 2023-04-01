#include "find_nearest.h"

#include <cmath>

#include "Food.h"
#include "math_function.h"

int find_nearest_food(const Cord& self_pos, const std::vector<Food*>& Foods,
                      const int& vision_Radius) {
  int ret = -1;
  int min = pow(vision_Radius, 2);
  int x, y;
  int sqDist;
  for (int i = 0; i < Foods.size(); i++) {
    x = Foods[i]->position.X;
    y = Foods[i]->position.Y;
    sqDist = sqDistance(Foods[i]->position, self_pos);
    if (sqDist < min)  //(pow(x - self_pos.X, 2) + pow(y - self_pos.Y, 2) < min)
    {
      min = sqDist;
      ret = i;
    }
  }
  return ret;
}

int Maxmin(const int& N, const int& M, const int& m) {
  if (N > M) return M;
  if (N < m) return m;
  return N;
}
