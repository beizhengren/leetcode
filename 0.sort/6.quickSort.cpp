/// https://blog.csdn.net/weixin_42861545/article/details/94404457#commentBox
//T(N) = O(n(logn))
/*思路
1.选取主元pivot。
  方法：median3。
  首先，首中尾的中间值作为主元，同时对这三个值排序(此时首<pivot, 尾>pivot,也就是首尾都已经划分好）。
  然后，将主元与倒数第二个元素交换，这样只需要考虑对区间[beg + 1, end - 2]的划分。
  最后，返回主元的索引pivotIdx。
  
2.根据主元划分数组.
  i = beg+1，j = end -2. 小于主元的放在左边(++i)，大于主元的放在右边(++j), 否则swap。
  最后一步交换主元和i的值.这样主元就放到了最终排序的应该放的位置。
  
3.根据2的结果，递归的划分除去主元之后的两个子数组。
*/
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
int medain3(T arr[], int l, int r) {
	int center = l + (r - l) / 2;
	if (arr[l] > arr[center]) swap(arr[l], arr[center]);
	if (arr[l] > arr[r])swap(arr[l], arr[r]);
	if (arr[center] > arr[r])swap(arr[center], arr[r]);
	// In this time, arr[left] <= arr[center] <= arr[right]
	// Hide the pivot on the position of right - 1
	swap(arr[center], arr[r - 1]);
	return r-1;
}

template <typename T>
void qSort(T arr[], int left, int right) {
	int cutoff = 2;//最小是2，保证最少有3个元素，可以使用medain3.一般可以是100.
	// If the sequence elements are suffciently large, use quick sort
	if (cutoff <= right - left) {
		int pivotIdx = medain3(arr, left, right);
		int low = left, high = right - 1;
		while (1) {
			// Move the sequence smaller than the reference to the left
			// and the big to the right
			while (arr[++low] < arr[pivotIdx]);//">="的时候停下来，相等的时候也要停下来交换，让
							  //主元最后放在比较靠中间的位置，保证O(nlogn)的。
			while (arr[--high] > arr[pivotIdx]);//"<="的时候停下来
			if (low < high) {
				swap(arr[low], arr[high]);
			}
			else break;
		}
		// Find the position `low` to place pivot
		// Change the pivot to the correct position low
		swap(arr[low], arr[pivotIdx]);
		//low这个位置的最终的元素已经放好，那么接下来要分别取递归左右两个子数组
		//把主元pivot（值）换到（比较中间的）位置low
		qSort(arr, left, low - 1);
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
