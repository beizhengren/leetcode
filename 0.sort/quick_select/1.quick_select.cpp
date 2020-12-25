// https://www.it610.com/article/1732716.htm

#include <iostream>
#include <vector>

using namespace std;

//search the kth biggest number
int QuickSelect(vector<int> &a, int left, int right, int k)
{
    int pivot = a[ left ];

    int i = left;
    int j = right;
    while( i < j )
     {
        //NOTE: ">=" not ">"
        while ( a[j] >= pivot && i < j )
             j-- ;
         a[i] = a[j];

        while ( a[i] <= pivot && i < j )
             i++ ;
         a[j] = a[i];
     }
     a[i] = pivot;

    //there are i+1 numbers from a[0] to a[i]
    if( k < i + 1 )
        return QuickSelect( a, left, i - 1 , k);
    else if( k > i + 1 )
        return QuickSelect( a, i + 1 , right, k);
    else
         return a[i];
}

int main(void )
{
     vector<int> a {4, 2, 1, 7, 10, 5, 3, 2};
    //the fourth one should be 3.
     cout<<QuickSelect(a, 0, a.size() - 1, 4) << '\n';
     
     vector<int> b {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
     cout << QuickSelect(b, 0, b.size() -1, 5) << '\n';
}
