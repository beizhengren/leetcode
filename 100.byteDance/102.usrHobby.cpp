//
// Created by wyz on 20-8-25.
//

/*
 输入：
 第1行为n代表用户的个数.第2行为n个整数，
 第i个代表用户标号为i的用户对某类文章的喜好度
 第3行为一个正整数q代表查询的组数
 第4行到第（3+q）行，每行包含3个整数l,r,k代表一组查询，即标号为l<=i<=r的用户中对这类文章喜好值为k的用户的个数。
 数据范围n <= 300000,q<=300000 k是整型
 */

/*
 输出：一共q行，每行一个整数代表喜好值为k的用户的个数
*/

/*
输入:
5
1 2 3 3 5
3
1 2 1
2 4 5
3 5 3
 */

/*
输出:
1
0
2
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    //vector<int> vecLike(n, 0);
    multimap<int, int> mapLike;
    for(int i = 0; i < n; ++i){
        int likeVal;
        cin >> likeVal;
        mapLike.insert(pair<int,int>(likeVal, i+1));
    }
    int lines;
    cin >> lines;

    for(int i = 0; i < lines; ++i){
        int l, r, k;
        int count = 0;
        cin >> l >> r >> k;
        auto low = mapLike.lower_bound(k);
        auto up = mapLike.upper_bound(k);
        if(low!= mapLike.end()){
            for(auto it = low; it !=up; ++it){
                if(it->second >= l && it->second <= r){
                    ++count;
                }
            }
        }

        cout << count << endl;
    }
}
