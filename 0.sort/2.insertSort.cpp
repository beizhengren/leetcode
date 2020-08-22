//
// Created by wyz on 20-8-22.
//
//最好情况: T = O(N)
//最坏情况: T = O(N^2)
//稳定.假设index=0的牌已经在手里了.
//排序的复杂度和逆序对个数有关.冒泡和插入排序都是两两互换,所以复杂度高.
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

template <typename T>
void insertSort(T& arr, int n){
    for(int i = 1; i < n; ++i){
        for(int idx = i; idx > 0; --idx ){
            if (arr[idx] < arr[idx-1]){
                swap(arr[idx], arr[idx-1]);
            }
        }
    }
}

template <typename T>
void insertSort2(T& arr, int n){
    for(int i = 1; i < n; ++i){
        auto tmp = arr[i];//必须用tmp保存arr[i],因为在移动前面的元素的时候原数组会被覆盖.
        int idx = i;
        for( ; idx > 0 && tmp < arr[idx-1]; --idx ){
                arr[idx] = arr[idx-1];
        }
        arr[idx] = tmp;
    }
}

template <typename T>
void printArr(T arr, int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << endl;
    }
}

int main (){
    array arr = {0, 5, 3, 2, 1, 9, 6, 7, 8};
    //insertSort(arr, arr.size());
    insertSort2(arr, arr.size());
    printArr(arr, arr.size());
}