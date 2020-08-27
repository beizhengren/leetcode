//递归版本
//T( N ) = O( N logN )， 稳定
#include<iostream>
using namespace std;
//merge two sorted sub array
void mergeSubArr(int arr[], int l, int m, int r, int arrTmp[]) {
	int size = r - l + 1;//注意size的大小

	int i = l, j = m + 1;
	int idx = l;//注意，这里起点是L，关系到递归的时候每次访问数组中的元素。
	while (i <= m && j <= r) {
		if (arr[i] < arr[j]) {
			arrTmp[idx++] = arr[i++];
		}
		else {
			arrTmp[idx++] = arr[j++];
		}
	}
	while (i <= m) {
		arrTmp[idx++] = arr[i++];
	}
	while (j <= r) {
		arrTmp[idx++] = arr[j++];
	}
	//将tmp对应数组元素赋值给原数组。此处（循环之前）r = idx -1
	for (int i = 0; i < size; ++i, --r) {
		arr[r] = arrTmp[r];
	}
}

void merge(int arr[], int l, int r, int tmp[]) {
	int mid;
	if (l < r) {
		mid = (l + r) / 2;
		merge(arr, l, mid, tmp);
		merge(arr, mid + 1, r, tmp);
		mergeSubArr(arr, l, mid, r, tmp);
	}
}


void mergeSort(int arr[], int n) {
	int* tmp = new int[n] {0};
	if (tmp != nullptr) {
		merge(arr, 0, n - 1, tmp);
		delete []tmp;
	}
	else {
		cerr << "out of memory space" << endl;
	}
	;
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << endl;
	}
}
int main() {
	int arr[] = { 9, 8, 7, 6, 5, 0, 1, 2, 3, 4 };
	mergeSort(arr, 10);
	printArr(arr, 10);
}
