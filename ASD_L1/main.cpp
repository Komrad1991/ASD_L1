#include "elem.h"
#include "task2.h"
#include <iostream>

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

int main()
{
	//task1();

	std::cout << countNEven(43) << std::endl;
}