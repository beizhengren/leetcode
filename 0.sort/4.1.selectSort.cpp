
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
// 由于寻找最小元的时候是两两比较,复杂度高
// 最坏 O( N^2 )
// 平均 O( N^2 )
// 即 theta = O( N^2 )

//找[startIndex, endIndex]中最小值的index
template <typename T>
int scanForMinPos( T& A, int sIdx, int eIdx ){
    int minIdx = sIdx;
    int tmpMin = A[sIdx];
    //既然是index,就是能取到eIdx.
    for(int i = sIdx + 1; i <= eIdx; ++i){
        if(A[i] < tmpMin){
            tmpMin = A[i];
            minIdx = i;
        }
    }
    return minIdx;
}

template <typename T>
void selectSort( T& A, int N ){
    for(int i = 1; i < N; ++i){
        int index = scanForMinPos(A, i, N-1);
        swap(A[i], A[index]);
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
    selectSort(arr, arr.size());
    printArr(arr, arr.size());
}
