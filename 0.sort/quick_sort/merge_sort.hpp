//
// Created by wyz on 20-11-18.
//

#ifndef QUICKSORT_MERGE_SORT_HPP
#define QUICKSORT_MERGE_SORT_HPP

#include <vector>

template<typename T>
void merge_sub(T* arr, int l, int mid, int r, T* arrTmp){
    int tmpIdx = l;
    int i = l;
    int j = mid + 1;

    while(i <= mid && j <=r){
        if(arr[i] < arr[j]){arrTmp[tmpIdx++] = arr[i++];}
        else {arrTmp[tmpIdx++] = arr[j++];}
    }
    while(i <= mid){arrTmp[tmpIdx++] = arr[i++];}
    while(j <= r){arrTmp[tmpIdx++] = arr[j++];}

    for(int i = l; i <= r; ++i){
        arr[i] = arrTmp[i];
    }

}

//因为需要merge的是子数组, 所以需要知道起始, 终止位置
template<typename T>
void merge(T*arr, int l, int r, T* arrTmp){
    if(l < r)
    {
        int mid = l + ((r - l)>>1);
        merge(arr, l, mid, arrTmp);
        merge(arr, mid + 1, r, arrTmp);
        merge_sub(arr, l, mid, r, arrTmp);
    }
}

template<typename T>
void merge_sort(T* arr, int totalNum){
    std::vector<T> arrTmp(totalNum);
    merge(arr, 0, totalNum-1, arrTmp.data());
}

template<typename T>
void merge_sort_test(T* arr, int beg, int end){
    merge_sort(arr, end + 1);
}

#endif //QUICKSORT_MERGE_SORT_HPP
