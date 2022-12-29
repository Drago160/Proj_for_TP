#include "random.h"

#include <cmath>
int random(const int& k) { return rand() % k; }

int Disp(const int& N, const int& k) {
  if (k == 0) return N;
  return N + random(2 * k) - k;
}

int randSign() {
  if (random(2) == 0) return 1;
  return -1;
}

bool rand_bool(const int& N) {
  if (random(100) <= N) return true;
  return false;
}

int f(const int& N, const int& dn, const int& k, const int& ret) {
  if (2 * dn > N - k) {
    return ret * randSign();
  }
  return f(N - 2 * dn, dn - 1, k, ret + 1);
}

int distrebute(const int& N, const int& dn) {
  if (N == 0) return 0;
  int Q = pow(dn + 1, 2);
  int k = random(Q) + 1;
  if (Q - k + 1 <= dn + 1) return N;
  return N + f(Q - dn - 1, dn, k, 1);
}
