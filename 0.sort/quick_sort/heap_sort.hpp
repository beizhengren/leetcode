//
// Created by wyz on 20-11-18.
//

#ifndef QUICKSORT_HEAP_SORT_HPP
#define QUICKSORT_HEAP_SORT_HPP
template <typename T>
void swap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void heapify(T* arr, int totalNum, int rootIdx){
    int largest = rootIdx; // Initialize largest as root
    int l = 2 * rootIdx + 1; // left = 2*rootIdx + 1
    int r = 2 * rootIdx + 2; // right = 2*rootIdx + 2

    // If left child is larger than root
    if (l < totalNum && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < totalNum && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != rootIdx)
    {
        swap(arr[rootIdx], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, totalNum, largest);
    }

}

template<typename T>
void heapify_opt(T* arr, int totalNum, int rootIdx){

    while(rootIdx < totalNum){
        //记录根节点和左,右子节点中最大的节点的idx
        int maxIdx = rootIdx;
        int childL = rootIdx * 2 + 1;
        int childR = rootIdx * 2 + 2;

        if(childL < totalNum && arr[childL] > arr[maxIdx]){ maxIdx = childL;}
        if(childR < totalNum && arr[childR] > arr[maxIdx]){ maxIdx = childR;}
        if(maxIdx != rootIdx){
            swap(arr[rootIdx], arr[maxIdx]);
            rootIdx = maxIdx;
        }else{
            break;
        }
    }
}

template<typename T>
inline void heap_sort(T* arr, int n){
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);//此处i是index,是以当前非叶子节点为树根。每次需要减1，向前调整堆.
    }

    //此处i是个数参数。因此最小是1.
    for (int i = n-1; i >0 ; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

template<typename T>
inline void heap_sort(T* arr, int, int n){
    //n + 1 is the total number of arr
    heap_sort(arr, n + 1);
}
template void heap_sort<int>(int*, int, int);
#endif //QUICKSORT_HEAP_SORT_HPP
