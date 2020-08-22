//
// Created by wyz on 20-8-22.
//

//最好情况:顺序 T = O(N)
//最坏情况:逆序 T = O(N^2)
//稳定.可以对链表进行排序
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T& arr, int n){
    for(int j = n-1; j >=0 ; --j){
        bool flag = false;
        for(int i = 0; i < j; ++i){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                flag = true;
            }
        }
        if(flag == false) break;
    }
}


int main (){
    array arr = {0, 5, 3, 2, 1, 9, 6, 7, 8};
    bubbleSort(arr, arr.size());
    for(const auto& a:arr){
        cout << a << endl;
    }
}