/*���������� ��������

����� O(n*log n) ������ O(n)

���������� �������� �Merge sort� � ��������,
������� ��������� ��������� ������, 
� ������� ������ � ��������� �������������� 
���������������.
*/

void merge(int* arr, int l, int m, int r)
{
    int nl = m - l + 1;
    int nr = r - m;

    // ������� ��������� �������
    int* left = new int[nl];
    int* right = new int[nr];

    // �������� ������ �� ��������� �������
    for (int i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < nr; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    int k = l;  // ������ ����� �����

    while (i < nl && j < nr) {
        // ���������� ����������� �������� ������� �� ������� ������
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
    // ���������� ���������� �������� ����� �����
    while (i < nl) {
        arr[k] = left[i];
        i++;
        k++;
    }
    // ���������� ���������� �������� ������ �����
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