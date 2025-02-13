#pragma once
#include <time.h>
#include <vector>
#include <algorithm>
#include <iostream>
class elem {
	int data;
public:
	// ���������� ������������ � ��������� �������� ������
	static size_t assigns, compares;

	// ����������� - ������������� ��������� ���������
	elem() {
		data = rand();
	};
	// ���������� �����������
	elem(const elem& other) : data(other.data) {
		++assigns;
	};
	// ����� ���������
	static void reset() {
		assigns = 0;
		compares = 0;
	}
	// ���������� �������� ��������� - ��� ���������� ����������
	bool operator<(const elem& other) const {
		++compares;
		return data < other.data;
	}
	// ���������� ��������� ������������
	const elem& operator=(const elem& other) {
		++assigns;
		data = other.data;
		return *this;
	}
	// ������������� ������� - �������� "��������� � �����"
	friend std::ostream& operator<<(std::ostream& out, const elem& item);
};
// ������������� ����������� ����� ������
size_t elem::assigns = 0;
size_t elem::compares = 0;
// ���������� �������� ������ � ����� - ��� ������������� �������
std::ostream& operator<<(std::ostream& out, const elem& item) {
	return out << item.data;
}
// ����������� ���������� ��� �������
void bubblesort(std::vector<elem>& vect) {
	for (size_t i = vect.size() - 1; i > 0; --i)
		for (size_t j = 0; j < i; ++j)
			if (vect[j + 1] < vect[j])
				std::swap(vect[j + 1], vect[j]);
}


// ������� ���������� ��� ������� - �������� ����������� ����������
void quicksort(std::vector<elem>& vect) {
	sort(vect.begin(), vect.end());
}
// ���������� ���������� ��� ������� - �������� ����������� ����������
void stablesort(std::vector<elem>& vect) {
	stable_sort(vect.begin(), vect.end());
}

void selection_sort(std::vector<elem>& vect)
{
	for (int i = 0; i < vect.size() - 2; i++)
	{
		int min = i;
		for (int j = min; j < vect.size() - 1; j++)
		{
			if (vect[j] < vect[min])
			{
				min = j;
			}
		}
		std::swap(vect[i], vect[min]);
	}
}