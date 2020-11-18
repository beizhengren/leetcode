#include<array>
#include<iostream>
#include<algorithm>
using namespace std;
#define RECURSIVE 0
//n is the max index of a completed tree, i is the root index of a sub tree
//从index=i开始，以i为根节点，向下调整数组为一个堆
template<typename T>
void heapify(T& arr, int totalNum, int rootIdx) {
#if RECURSIVE==0
	cout << "not recursive" << endl;
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
#else
	cout << "recursive" << endl;
    	int largest = rootIdx; // Initialize largest as root
	int l = 2 * rootIdx + 1; // left = 2*rootIdx + 1
	int r = 2 * rootIdx + 2; // right = 2*rootIdx + 2

	// If left child is larger than root
	if (l < totalNum && arr[l] > arr[largest]){ largest = l;}

	// If right child is larger than largest so far
	if (r < totalNum && arr[r] > arr[largest]){ largest = r;}

	// If largest is not root
	if (largest != rootIdx)	{
		swap(arr[rootIdx], arr[largest]);
		// Recursively heapify the affected sub-tree
		heapify(arr, totalNum, largest);
	}
#endif // !RECURSIVE

}

//n is the total num of tree nodes
template<typename T>
void heapSort(T& arr, int n) {
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
void printArr(const T& arr) {
	for (const auto & a : arr) {
		cout << a << " " << endl;
	}
}
int main() {
	array arr = { 5, 4, 3, 2, 1, 0, 6, 7, 8, 9 };
	heapSort(arr, arr.size());
	printArr(arr);
}


