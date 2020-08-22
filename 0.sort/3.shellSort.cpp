//
// Created by wyz on 20-8-22.
//

//非互质增量序列:theta(N^2)
//互质增量序列:
// 最坏 O( N^(4/3) )
// 平均 O( N^(5/4) )

//间的隔插入排序:一次可以消掉多个逆序对.间隔递减.1间隔的时候做的是原始插入排序.
//设置互质的增量序列.
//O是上界.奥米伽是下界.而theta是上下界统一的.
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

template <typename T>
void shellSort( T& A, int N )
{ /* 希尔排序 - 用Sedgewick增量序列 */
    int shellIndex, shellValue, v, i;

    /* 这里只列出一小部分增量 */
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

    for ( shellIndex=0; Sedgewick[shellIndex]>=N; shellIndex++ )
        ; /* 初始的增量Sedgewick[shellIndex]不能超过待排序列长度 */

    for ( shellValue = Sedgewick[shellIndex]; shellValue>0; shellValue=Sedgewick[++shellIndex] ){
        for ( v = shellValue; v < N; v++ ) { /* 插入排序*///将原始的1换成shellValue
            for(int i = v; i - shellValue >= 0; i-=shellValue){
                if(A[i] < A [i-shellValue]){
                    swap(A[i], A[i - shellValue]);
                }
            }
        }
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
    shellSort(arr, arr.size());
    printArr(arr, arr.size());
}