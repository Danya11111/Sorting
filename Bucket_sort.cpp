/*Карманная сортировка

Время O(n + k*n^2 + k) Память O(n*k)

Алгоритм карманной сортировки предполагает, 
что на вход поступает массив значений, 
где каждое значение лежит в промежутке [0, 1) 
(значения от 0 включительно до 1 но не включая саму 1-цу,
или если записывать неравенством 0 <= x < 1 ) ,
и предполагается, что значения равномерно распределены, 
тогда время работы алгоритма будет линейным O(n).
*/

#include "Sortirovki.h"

struct bucket {
    int count; // количество элементов в корзине
    int* data; // массив элементов корзины
};

int getExp(int value) {
    int exp = 1;

    while (value > 10)
    {
        value /= 10;
        exp *= 10;
    }

    return exp;
}

void countSort(int* arr, int n)
{
    if (!n)
        return;
    int* output = new int[n];
    int max = getMax(arr, n);
    int* count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;  // подсчитываем  частоту повторения элементов

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];  // вычисляем накопленные суммы

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];  // устанавливаем элемент на корректное место 
        count[arr[i]]--; // уменьшаем частоту, так как уже записали элемент
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
    delete[] count;
}

void Bucket_sort(int* arr, int n)
{
    struct bucket buckets[10];
    // вычисляем значение экспоненты
    int exp = getExp(getMax(arr, n));

    for (int i = 0; i < 10; i++)
    {
        buckets[i].count = 0;
        buckets[i].data = new int[n];
    }
    for (int i = 0; i < n; i++) {
        int bi = arr[i] / exp; // вычисляем индекс корзины
        buckets[bi].data[buckets[bi].count++] = arr[i]; // добавляем элемент в корзину
    }
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        countSort(buckets[i].data, buckets[i].count);
        for (int j = 0; j < buckets[i].count; j++) {
            arr[cnt] = buckets[i].data[j];
            cnt++;
        }
    }
    
    // здесь реализуйте шаг 4 описанный в алгоритме
}