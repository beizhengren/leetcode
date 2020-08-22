//
// Created by wyz on 20-8-22.
//
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

//堆排序是对选择排序的优化, 在找最小元的时候用最大堆作为辅助.
//堆排序的平均复杂度是O(N*logN).但是实际效果不如Sedgewick增量序列的shell排序.

//树的遍历:
// pre: root->left->right
// post: left->right->root
// in: left->root->right

//完美二叉树(Perfect Binary Tree)/满二叉树(Full Binary Tree)
//完全二叉树(Complete Binary Tree)

//二叉搜索树(BST):空或者非空. 非空:左子树的所有键值<根节点键值<右子树的所有键值;左右子树都是二叉搜索树.不要求是CBT.
//平衡二叉树(AVL):空或者非空. 非空:任意节点的左、右子树的高度差的绝对值<=1

//大顶堆: 完全二叉树, 每个节点的值不小于左右儿子节点的值. 和BST不同, 左右儿子的键值并没有大小的要求

//堆可以二叉树或者数组来表示.
template<typename ElementType>
void Swap( ElementType *a, ElementType *b )
{
    ElementType t = *a; *a = *b; *b = t;
}

template<typename ElementType>
void PercDown( ElementType A[], int p, int N )
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
    /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;

    X = A[p]; /* 取出根结点存放的值 */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= A[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}

template<typename ElementType>
void HeapSort( ElementType A[], int N )
{ /* 堆排序 */
    int i;

    for ( i=N/2-1; i>=0; i-- )/* 建立最大堆 */
        PercDown( A, i, N );

    for ( i=N-1; i>0; i-- ) {
        /* 删除最大堆顶 */
        Swap( &A[0], &A[i] ); /* 见代码7.1 */
        PercDown( A, 0, i );
    }
}

template <typename T>
void printArr(T arr, int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << endl;
    }
}

int main (){
    // array arr = {0, 5, 4, 3, 2, 1, 9, 6, 7, 8};
    int arr[] = {0, 5, 4, 3, 2, 1, 9, 6, 7, 8};
    HeapSort(arr, 10);
    printArr(arr, 10);
}