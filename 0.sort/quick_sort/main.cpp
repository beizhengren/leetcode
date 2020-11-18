//
// Created by wyz on 20-11-17.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include "my_test.hpp"
#include "quick_sort.hpp"
#include "heap_sort.hpp"
using namespace std;

template <typename T> void printArr(T arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << endl;
}

int main() {

    int arr1[] = { 1, 2, 3, 4, 5, 0, 6, 7, 8, 9 };
    int n = sizeof(arr1) / sizeof(int);
    heap_sort(arr1, 0, n);
    printArr(arr1, n);

#define MAX_N 10000000
    int *arr = getRandData(MAX_N);
    TEST(quick_sort_v1, arr, MAX_N);
    TEST(quick_sort_v1_opt, arr, MAX_N);
    TEST(quick_sort_vn, arr, MAX_N);
    TEST(quick_sort_vn_opt, arr, MAX_N);
    TEST(heap_sort, arr, MAX_N);
#undef MAX_N
    return 0;
}
/*
[    OK    ] quick_sort_v1 (1418 ms)
[    OK    ] quick_sort_v1_opt (1412 ms)
[    OK    ] quick_sort_vn (1606 ms)
[    OK    ] quick_sort_vn_opt (1567 ms)
[    OK    ] heap_sort (4441 ms)
*/
