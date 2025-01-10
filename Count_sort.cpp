/* Сортировка подсчетом

Время O(n+k) Память O(n+k)

Данный тип сортировки применим для массивов 
состоящих из целых чисел в промежутке от 0 до m, 
либо массивов, состоящих из сложных объектов.
*/
#include "Sortirovki.h"

void Count_sort(int* arr, int n) {

	int* output = new int[n];
	int max = getMax(arr, n);
	int* count = new int[max + 1];

	for (int i = 0; i < max + 1; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[arr[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (int i = 0; i < n; i++)
		arr[i] = output[i];

	delete[] output;
	delete[] count;
}