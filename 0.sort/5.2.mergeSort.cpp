//最坏和平均都是 nlogn。稳定
//适合外排序。如果都是在内存完成，没人用归并排序。
#include<iostream>
using namespace std;

//merge two sorted sub array
void mergeSubArr2(int arr[], int l, int m, int r, int arrTmp[]) {
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
	////这里和递归中的不同
	//for (int i = 0; i < size; ++i, --r) {
	//	arr[r] = arrTmp[r];
	//}
}

//一趟归并
void mergePass(int arr[], int n, int length, int arrTmp[]) {
	//两两归并相邻有序子列
	int i, j;
	//从左到右一对儿一对儿的调用mergeSubArr
	//length是当前有序子列的长度。
	//i+=2*length,跳过两个子列，去找下一对儿。
	for (i = 0; i <= n - 2 * length; i += 2 * length) {
		mergeSubArr2(arr, i, i + length -1, i + 2 * length - 1, arrTmp);
	}
	if (i + length < n) {
		//归并最后两个子列
		mergeSubArr2(arr, i, i + length -1, n-1, arrTmp);
	}
	else {
		for (j = i; j < n; ++j) {
			arrTmp[j] = arr[j];
		}

	}
}


void mergeSort(int arr[], int n) {
	int* arrTmp = new int[n];
	int length = 1;//初始化子序列的长度

	if (arrTmp != nullptr) {
		//每次循环做两次mergePass，保证跳出循环结果肯定是存在arr中的。
		while (length < n) {
			mergePass(arr, n, length, arrTmp);//arr中的结果倒到 arrTmp
			length *= 2;
			mergePass(arrTmp, n, length, arr);//arrTmp中的结果倒到 arr
			length *= 2;
		}
		delete[]arrTmp;
	}
	else {
		cerr << "out of memory space" << endl;
	}
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
