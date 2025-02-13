#include "task2.h"
#include <string>
#include <iostream>
#include <vector>


long long int countNEven(long long int n)
{
	int realN = n - 2;
	return recur(realN, 1);
}

long long int recur(long long int n, int pred)
{
	if (n == 0 && pred == 1) return 1;
	else if (n == 0) return 0;
	if (pred == 0) return recur(n - 1, 1);
	else return recur(n - 1, 1) + recur(n - 1, 0);
}
