/*—ортировка сли€нием

¬рем€ O(n*log n) ѕам€ть O(n)

—ортировка сли€нием УMerge sortФ Ч алгоритм,
который сортирует структуры данных, 
в которых доступ к элементам осуществл€етс€ 
последовательно.
*/

void merge(int* arr, int l, int m, int r)
{
    int nl = m - l + 1;
    int nr = r - m;

    // создаем временные массивы
    int* left = new int[nl];
    int* right = new int[nr];

    // копируем данные во временные массивы
    for (int i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < nr; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    int k = l;  // начало левой части

    while (i < nl && j < nr) {
        // записываем минимальные элементы обратно во входной массив
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // записываем оставшиес€ элементы левой части
    while (i < nl) {
        arr[k] = left[i];
        i++;
        k++;
    }
    // записываем оставшиес€ элементы правой части
    while (j < nr) {
        arr[k] = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}

void Merge_sort(int* arr, int l, int r) {
    if (l >= r)
        return;
    int m = (l + r - 1) / 2;
    Merge_sort(arr, l, m);
    Merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}