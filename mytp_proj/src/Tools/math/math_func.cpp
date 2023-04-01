#include <cmath>
#include <iostream>

#include "CONSTANT.h"
#include "math_function.h"
#include "tools.h"

int sqDistance(const Cord& Point1, const Cord& Point2) {
  return pow((Point1.X - Point2.X), 2) + pow((Point1.Y - Point2.Y), 2);
}

struct Direction Rotate(const struct Direction& d, bool sign) {
  struct Direction ret;
  float x, y;
  x = d.X;
  y = d.Y;

  ret.X = x * d_cos + -1 * y * sign * d_sin;

  ret.Y = x * d_sin * sign + y * d_cos;

  float abs = sqrt(ret.X * ret.X + ret.Y * ret.Y);
  ret.X /= abs;
  ret.Y /= abs;

  return ret;
}

struct Direction Round_to(struct Direction src, struct Direction dst,
                          float delat) {
  float cos = src.X * dst.X + src.Y * dst.Y;
  if (cos >= 0)
    if (cos < d_cos)
      return dst;
    else
      return Rotate(src, src.Y < dst.Y);
  else
    return Rotate(src, src.Y < dst.Y);
}
