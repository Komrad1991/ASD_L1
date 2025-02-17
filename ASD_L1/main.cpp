#include "elem.h"
#include "task2.h"
#include <iostream>
#include "task3.h"
#include <chrono>
#include <ctime>
#include <fstream>
#include <math.h>

int task1()
{
	// Инициализируем генератор случайных чисел
	srand(static_cast<unsigned int>(time(NULL)));
	// Объявляем два идентичных вектора указанного размера
	std::cout << "Vector size : ";
	size_t n;
	std::cin >> n;
	std::vector<elem> v1(n), v2(v1), v3(v1);

	// Выводим информацию о количествах присваиваний и сравнений
	std::cout << "Vectors created : " << v1.size() << " elements\n";
	std::cout << "Assigns : " << elem::assigns << " comparisons : ";
	std::cout << elem::compares << std::endl;
	// Выполняем обнуление счетчиков и устойчивую сортировку
	elem::reset();
	stablesort(v1);
	std::cout << "\nStable sort: assigns : " << elem::assigns;
	std::cout << " comparisons : " << elem::compares;
	elem::reset();
	// Быстрая сортировка - алгоритм из стандартной библиотеки C++
	quicksort(v2);
	// Выводим информацию о количествах присваиваний и сравнений в процессе сортировки
	std::cout << "\nQuick sort: assigns : " << elem::assigns;
	std::cout << " comparisons : " << elem::compares << std::endl;

	//сортировка выбором
	elem::reset();
	selection_sort(v3);
	std::cout << "\nSelection_sort: assigns : " << elem::assigns;
	std::cout << " comparisons : " << elem::compares << std::endl; //мало присваиваний, но очень много сравнений, что растет с кол-вом элементов
	//for (auto x : v3)
	//{
	//	std::cout << x << " ";
	//}
	return 0;
}

void task3()
{
	
	std::vector<int> primes = { 2,	31, 127, 1019 };
	std::vector<long long> primes_res;
	for (int i = 0; i < primes.size(); i++)
	{
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		factorizator(primes[i]);
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		primes_res.push_back(dur);
	}

	srand(static_cast<unsigned int>(time(NULL)));
	std::vector<int> rand_nums;
	for (int i = 10; i > 0; i--)
	{
		rand_nums.push_back(rand() % ((int)pow(10,i+1) - (int)pow(10, i) + 1) + pow(10, i));
	}
	std::reverse(rand_nums.begin(), rand_nums.end());
	std::vector<long long> rand_res;
	for (int i = 0; i < rand_nums.size(); i++)
	{
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		factorizator(rand_nums[i]);
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		std::cout << dur << std::endl;
		rand_res.push_back(dur);
	}

	std::vector<int> below7 = { 168,840,5040,25200,100800,352800,705600,1411200,2822400,5644800 };
	std::vector<long long> below7_res;
	for (int i = 0; i < rand_nums.size(); i++)
	{
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		factorizator(below7[i]);
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		below7_res.push_back(dur);
	}
	std::ofstream f;
	f.open("graph.csv");
	for (int i = 0; i < primes_res.size(); i++)
	{
		std::cout << primes_res[i] << std::endl;
		f << primes_res[i] << " , ";
	}
	f << "\n";
	for (int i = 0; i < rand_res.size(); i++)
	{
		std::cout << rand_res[i] << std::endl;
		f << rand_res[i] << " , ";
	}
	f << "\n";
	for (int i = 0; i < below7_res.size(); i++)
	{
		std::cout << below7_res[i] << std::endl;
		f << below7_res[i] << " , ";
	}
	f << "\n";
}

int main()
{
	//task1();

	//std::cout << countNEven(30) << std::endl;

	task3();
}