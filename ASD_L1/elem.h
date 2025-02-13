#pragma once
#include <time.h>
#include <vector>
#include <algorithm>
#include <iostream>
class elem {
	int data;
public:
	// Количество присваиваний и сравнений объектов класса
	static size_t assigns, compares;

	// Конструктор - инициализация случайным значением
	elem() {
		data = rand();
	};
	// Копирующий конструктор
	elem(const elem& other) : data(other.data) {
		++assigns;
	};
	// Сброс счетчиков
	static void reset() {
		assigns = 0;
		compares = 0;
	}
	// Перегрузка операции сравнения - для сортировок достаточно
	bool operator<(const elem& other) const {
		++compares;
		return data < other.data;
	}
	// Перегрузка оператора присваивания
	const elem& operator=(const elem& other) {
		++assigns;
		data = other.data;
		return *this;
	}
	// Дружественная функция - операция "поместить в поток"
	friend std::ostream& operator<<(std::ostream& out, const elem& item);
};
// Инициализация статических полей класса
size_t elem::assigns = 0;
size_t elem::compares = 0;
// Перегрузка операции вывода в поток - как дружественная функция
std::ostream& operator<<(std::ostream& out, const elem& item) {
	return out << item.data;
}
// Пузырьковая сортировка для вектора
void bubblesort(std::vector<elem>& vect) {
	for (size_t i = vect.size() - 1; i > 0; --i)
		for (size_t j = 0; j < i; ++j)
			if (vect[j + 1] < vect[j])
				std::swap(vect[j + 1], vect[j]);
}


// Быстрая сортировка для вектора - алгоритм стандартной библиотеки
void quicksort(std::vector<elem>& vect) {
	sort(vect.begin(), vect.end());
}
// Устойчивая сортировка для вектора - алгоритм стандартной библиотеки
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