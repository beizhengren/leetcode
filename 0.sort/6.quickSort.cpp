#include <iostream>
using namespace std;
// https://blog.csdn.net/weixin_42861545/article/details/94404457#commentBox

/****************************************
void bubbleSort(int *a, const int &n);
// Uniform interface
void quickSort(int *a, const int &n);
// Core recursion function
void qSort(int *a, int left, int right);
int median3(int* arr, int left, int right);
void swap(int& a, int& b);
*****************************************/

// Time complexity best case: n, worst case: n^2
void bubbleSort(int *a, const int &n){
    int flag = 0;
    int tmp = 0;
    for (int p = n - 1; p; p--){
        flag = 0;
        for (int i = 0; i < p; i++){
            if (a[i] > a[i + 1]){
                tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                flag = 1;  // Identification has exchanged
            }
            if (flag == 0){
                break;
            }
        }  // of for i
    }  // of for p
}  // of function

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

int median3(int arr[], int left, int right){
    int center = left + (right - left) / 2;  // Use this form to prevent overflow
    if (arr[left] > arr[center]){
        swap(arr[left], arr[center]);
    }
    if (arr[left] > arr[right]){
        swap(arr[left], arr[right]);
    }
    if (arr[center] > arr[right]){
        swap(arr[center], arr[right]);
    }
    // In this time, arr[left] <= arr[center] <= arr[right]
    // Hide the pivot on the position of right-1
    swap(arr[center], arr[right - 1]);
    return arr[right - 1];
}

// Core recursion function
void qSort(int *a, int left, int right){
    int pivot = 0;
    int cutoff = 2;//最小是2
    int low = 0;
    int high = 0;

    // If the sequence elements are suffciently large, use quick sort
    if (cutoff <= right - left)	{

        pivot = median3(a, left, right);
        low = left;
        high = right - 1;
        while (1)		{
            // Move the sequence smaller than the reference to the left
            // and the big to the right
            while (a[++low] < pivot);
            while (a[--high] > pivot);
            if (low < high){
                swap(a[low], a[high]);
            }else{
                break;
            }
        }
        // Change the pivot to the correct position
        swap(a[low], a[right - 1]);
        qSort(a, left, low - 1);
        qSort(a, low + 1, right);
    }
        // If there's too few elements, use simple sort
    else{
        bubbleSort(a + left, right - left + 1);
    }
}

// Uniform interface
void quickSort(int *a, const int &n){
    qSort(a, 0, n - 1);
}


int main(){
    int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    for (int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    quickSort(a, 10);
    for (int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    return 0;
}