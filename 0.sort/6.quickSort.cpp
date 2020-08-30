/// https://blog.csdn.net/weixin_42861545/article/details/94404457#commentBox
#include<iostream>
using namespace std;

template <typename T>
void printArr(T arr[], int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << endl;
}
template <typename T>
void bubbleSort(T arr[], int n) {
	for (int j = n - 1; j >= 0; --j) {
		bool isSorted = false;
		for (int i = 0; i < j; ++i) {
			if (arr[i] > arr[i + 1]) {
				isSorted = true;
				swap(arr[i], arr[i + 1]);
			}
		}
		if (isSorted) break;
	}
	
}

template <typename T>
T medain3(T arr[], int l, int r) {
	int center = l + (r - l) / 2;
	if (arr[l] > arr[center]) swap(arr[l], arr[center]);
	if (arr[l] > arr[r])swap(arr[l], arr[r]);
	if (arr[center]>arr[r])swap(arr[center], arr[r]);
	// In this time, arr[left] <= arr[center] <= arr[right]
	// Hide the pivot on the position of right - 1
	swap(arr[center], arr[r - 1]);
	return arr[r - 1];
}

template <typename T>
void qSort(T arr[], int left, int right) {
	int cutoff = 2;//最小是2
	// If the sequence elements are suffciently large, use quick sort
	if (cutoff <= right - left) {
		T pivot = medain3(arr, left, right);
		int low = left, high = right - 1;
		while (1) {
			// Move the sequence smaller than the reference to the left
			// and the big to the right
			while (arr[++low] < pivot);
			while (arr[--high] > pivot);
			if (low < high) {
				swap(arr[low], arr[high]);
			}
			else break;
		}
		// Find the position `low` to place pivot
		// Change the pivot to the correct position
		swap(arr[low], arr[right - 1]);
		qSort(arr, left, low-1);
		qSort(arr, low + 1, right);
	} 
	// If there's too few elements, use simple sort
	else {
		bubbleSort(arr + left, right - left + 1);
	}
}

template <typename T>
void quickSort(T arr[], int n) {
	qSort(arr, 0, n - 1);
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 0, 6, 7, 8, 9 };
	int n = sizeof(arr) / sizeof(int);
	quickSort(arr, n);
	printArr(arr, n);
}
