#include "task3.h"
#include <iostream>
#include <vector>

void factorizator(long long int num)
{
	long long int orig = num;
	std::vector<int> res;
	std::vector<int> primes = { 2,	3,	5,	7,	11,	13,	17,	19,	23,	29, 127, 1019 };
	for (int i = 0; i < primes.size(); i++)
	{
		res.push_back(0);
		while (num % primes[i] == 0)
		{
			num /= primes[i];
			++res[i];
		}
	}
	//std::cout << orig << " = " << primes[0] << "^" << res[0];
	//for (int i = 1; i < primes.size(); i++)
	//{
	//	std::cout << " + ";
	//	std::cout << primes[i] << "^" << res[i];
	//}
	//std::cout << std::endl;
}