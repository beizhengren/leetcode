//
// Created by wyz on 20-8-25.
//

/*P为给定的二维平面整数点集。
定义P中某点x，如果x满足P中任意点都不在x的右上方区域内（横纵坐标都大于x），
则称其为“最大的”。求出所有“最大的”点的集合。
(所有点的横坐标和纵坐标都不重复,坐标轴范围在[0, 1e9]内）


如下图：实心点为满足条件的点的集合。

请实现代码找到集合P中的所有”最大“点的集合并输出。

*/

/*
第一行输入点集的个数N， 接下来N行，每行两个数字代表点的X轴和Y轴。1 ≤ n ≤ 500000
输出“最大的”点集合， 按照X轴从小到大的方式输出，每行两个数字分别代表点的X轴和Y轴。
5
1 2
5 3
4 6
7 5
9 0
*/

/*
4 6
7 5
9 0
 */
#include <vector>
#include <map>
#include <iostream>
using namespace std;

void printMap(const multimap<int, int>& m){
    for(auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
}


int main(){
    int N;
    multimap<int, int, greater<int> > firstMap;
    multimap<int, int, greater<int> > secondMap;
    cin >> N;
    for(int i = 0; i < N; ++i){
        int x, y;
        cin >> x >> y;
        firstMap.insert(pair<int, int>(x, y));
        secondMap.insert(pair<int, int>(y, x));
    }

    multimap<int,int> res;
    auto itX = firstMap.begin();
    auto itY = secondMap.begin();
    res.insert(pair<int, int>(itX->first, itX->second));
    res.insert(pair<int, int>(itY->second, itY->first));
    if(itX->first == itY->second && itX->second == itY->first) res.erase(itX->first);

    int yVauleOfFirstXmax = itX->second;
    int xValueOfsecondYmax = itY->second;
    ++itX, ++itY;

    for(auto& it = itX; it!= firstMap.end(); ++it){
        if(it->second > xValueOfsecondYmax) res.insert(*it);
    }
    for(auto& it = itY; it!= secondMap.end(); ++it){
        if(it->second > yVauleOfFirstXmax) {
            auto low = res.lower_bound(it->second);//res的first是x, 按照x来找
            auto up = res.upper_bound(it->second);
            bool isExisted = false;
            if(low != res.end()){
                for(auto& it2 = low; it2 != up; ++it2){//如果res中有相同的,跳出此层循环
                    if(it2->first == it->first && it2->first == it->second){
                        isExisted = true;
                        break;
                    }
                }
            }
            if(!isExisted)
                res.insert(pair<int, int>(it->second, it->first));
        }
    }

    printMap(res);
}