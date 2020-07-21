//
// Created by wyz on 20-7-21.
//
#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        int times = 0;
        for(auto& a:A)
            for(auto& b:B)
                m[a+b]++;
        for(auto& c:C)
            for(auto& d:D){
                auto it = m.find(0-c-d);
                if(it!=m.end())
                    times+= it->second;
            }
        return times;
    }
};

int main(){
    vector vecA{1, 2}, vecB{-2, -1}, vecC{-1, 2}, vecD{0 ,2};
    auto p = make_unique<Solution>();
    auto res = p->fourSumCount(vecA, vecB, vecC, vecD);
    cout << res << endl;
}
