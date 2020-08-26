#include<array>
#include<iostream>
#include<algorithm>
using namespace std;
#define RECURSIVE 0
//n is the max index of a completed tree, i is the root index of a sub tree
//从index=i开始，以i为根节点，向下调整数组为一个堆
template<typename T>
void heapify(T& arr, int n, int i) {
#if RECURSIVE==0
	cout << "not recursive" << endl;
	int parent, child;
  //2 * parent + 1 < n 也可以
	for (parent = i; parent < n; parent = child) {
		int cl = 2 * parent + 1;
		int cr = 2 * parent + 2;
		child = cl;
		if (cl < n) {
			if (cr < n) {
				if (arr[cl] < arr[cr])
					child = cr;
			}

			if (arr[parent] >= arr[child]) {
				break;
			}
			else {
				swap(arr[parent], arr[child]);
			}
		}

	}
#else
	cout << "recursive" << endl;
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
#endif // !RECURSIVE

}

//n is the total num of tree nodes
template<typename T>
void heapSort(T& arr, int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {
		heapify(arr, n, i);//此处i是index，每次需要减1.
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


