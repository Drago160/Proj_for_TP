#include<cmath>
int random(const int& k)
{
	return rand() % k;
}

int Disp(const int& N, const int& k)
{
	return  N + random(2*k) - k;
}


int randSign()
{
	if (random(2) == 0)
		return 1;
	return -1;
}

