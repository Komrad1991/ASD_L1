#include "elem.h"
#include "task2.h"
#include <iostream>

int task1()
{
	// �������������� ��������� ��������� �����
	srand(static_cast<unsigned int>(time(NULL)));
	// ��������� ��� ���������� ������� ���������� �������
	std::cout << "Vector size : ";
	size_t n;
	std::cin >> n;
	std::vector<elem> v1(n), v2(v1), v3(v1);

	// ������� ���������� � ����������� ������������ � ���������
	std::cout << "Vectors created : " << v1.size() << " elements\n";
	std::cout << "Assigns : " << elem::assigns << " comparisons : ";
	std::cout << elem::compares << std::endl;
	// ��������� ��������� ��������� � ���������� ����������
	elem::reset();
	stablesort(v1);
	std::cout << "\nStable sort: assigns : " << elem::assigns;
	std::cout << " comparisons : " << elem::compares;
	elem::reset();
	// ������� ���������� - �������� �� ����������� ���������� C++
	quicksort(v2);
	// ������� ���������� � ����������� ������������ � ��������� � �������� ����������
	std::cout << "\nQuick sort: assigns : " << elem::assigns;
	std::cout << " comparisons : " << elem::compares << std::endl;

	//���������� �������
	elem::reset();
	selection_sort(v3);
	std::cout << "\nSelection_sort: assigns : " << elem::assigns;
	std::cout << " comparisons : " << elem::compares << std::endl; //���� ������������, �� ����� ����� ���������, ��� ������ � ���-��� ���������
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