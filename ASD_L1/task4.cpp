#include "task4.h"

long long task4()
{
	return t4_rec(true,2) + t4_rec(false,2) * 4;
}

long long t4_rec(bool predPrime,int period)
{
	if (period == 11)
	{
		return predPrime ? 5 : 9;
	}
	return t4_rec(false, period + 1) * 6 + (predPrime ? 0 : t4_rec(true, period + 1) * 4);
}