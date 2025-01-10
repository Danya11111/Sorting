#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Sortirovki.h"

using namespace std;

void write_arr(const string& filename, const int* arr, const int n) {
    fstream fs;

    fs.open(filename, fstream::out);
    if (fs.is_open()) {
        fs << n << '\n';
        for (int i = 0; i < n; i++) {
            fs << arr[i] << ' ';
        }
        fs << '\n';
        fs.close();
    }
}

void read_arr(const string& filename, int*& arr, int& n) {
    fstream fs;

    fs.open(filename, fstream::in);
    if (fs.is_open()) {
        fs >> n;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            fs >> arr[i];
        }
        fs.close();
    }
}

void vivod(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void copy(int* arr,int* arr1, int n) {
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }
}
int main() {
    string filename = "C://Users/Daniil Arkhipov/source/repos/Test.txt";
    const int size = 1000;
    int* rand_arr = new int[size];
    int* arr1 = new int[size];
    srand(time(nullptr));
    int lef_border = 0;
    int range_len = 100;
    for (int i = 0; i < size; i++) {
        rand_arr[i] = rand();
    }
    write_arr(filename, rand_arr, size);
    int* array_from_file = nullptr;
    int n = 0;
    read_arr(filename, array_from_file, n);
    //vivod(array_from_file, n);

    copy(array_from_file, arr1, n);
    auto start = chrono::high_resolution_clock::now();
    Count_sort(arr1, n);
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Count_sort: " << endl;
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;
    //vivod(array_from_file, n);
    cout << endl;

    copy(array_from_file, arr1, n);
    start = chrono::high_resolution_clock::now();
    Radix_sort(arr1, n);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Radix_sort: " << endl;
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;
    //vivod(array_from_file, n);
    cout << endl;

    copy(array_from_file, arr1, n);
    start = chrono::high_resolution_clock::now();
    Bucket_sort(arr1, n);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Bucket_sort: " << endl;
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;
    //vivod(array_from_file, n);
    cout << endl;

    copy(array_from_file, arr1, n);
    start = chrono::high_resolution_clock::now();
    Bubble_sort(arr1, n);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Bubble_sort: " << endl;
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;
    //vivod(array_from_file, n);
    cout << endl;

    copy(array_from_file, arr1, n);
    start = chrono::high_resolution_clock::now();
    Merge_sort(arr1, 0, n - 1);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Merge_sort: " << endl;
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;
    //vivod(array_from_file, n);
    cout << endl;

    copy(array_from_file, arr1, n);
    start = chrono::high_resolution_clock::now();
    Insertion_sort(arr1, n);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Insertion_sort: " << endl;
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;
    //vivod(array_from_file, n);
    cout << endl;

    copy(array_from_file, arr1, n);
    start = chrono::high_resolution_clock::now();
    Selection_sort(arr1, n);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Selection_sort: " << endl;
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;
    //vivod(array_from_file, n);
    cout << endl;

    copy(array_from_file, arr1, n);
    start = chrono::high_resolution_clock::now();
    Tim_sort(arr1, n);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Tim_sort: " << endl;
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;
    //vivod(array_from_file, n);
    cout << endl;

    copy(array_from_file, arr1, n);
    start = chrono::high_resolution_clock::now();
    Quick_sort(arr1, 1, n - 1);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    cout << "Quick_sort: " << endl;
    cout << "Elapsed time: " << elapsed.count() << " sec" << endl;
    //vivod(array_from_file, n);
    cout << endl;
    return 0;
}