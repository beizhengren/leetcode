//
// Created by wyz on 20-8-25.
//
/*
主要思路就是每读取一个数字，就判断窗口是否满足最大值减去最小值不大于距离D；
由于每次进行计算组合之后，窗口的begin都会往前移动一位，所以计算组合应该采用固定首位的方法，
即固定首位有一人，接下来的位置的可能性，这样就可以保证窗口移动过程不会出现重复，因为下一次判断已经不包含上一个的首位置了。
*/
#include <iostream>
#include <vector>
using namespace std;
/*
long long C(long long n) {
    return (n-1) * n / 2;
}

int main()
{
    int N, D; cin>> N >> D;
    long long count = 0;
    vector<int> res(N);
    for (int end = 0, begin = 0; end < N; end++) {
        cin>> res[end];
        while (end >= 2 && (res[end] - res[begin]) > D) {
            begin++;//不满足则begin往前移动
        }
        count += C(end - begin);//由于判断一次往前移动（for循环中的end++），即可以采用每次固定首位的组合。
    }
    cout << count % 99997867;
}*/

long long Combine(long long n){
    return n * (n-1) / 2;
}
int main(){
    int N, D;
    cin >> N >> D;
    long long count = 0;

    vector<int> vec(N);
    for(int i = 0; i < N; ++i){
        cin >> vec[i];
    }

    for(int begin = 0, end = 2; end < N; ++end){
        while(vec[end] - vec[begin] > D){
            begin++;
        }
        count += Combine(end - begin);//需要组合的子数组长度
    }

    cout << count % 99997867;
}