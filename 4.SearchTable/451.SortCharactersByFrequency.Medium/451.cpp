//
// Created by wyz on 20-7-21.
//
#include <string>
#include <map>
#include <unordered_map>
#include <memory>
#include <iostream>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m1;
        for(const auto& it: s){
            m1[it]++;
        }

        multimap<int, char, greater<int> > m2;
        for(const auto& it : m1){
            m2.insert({it.second, it.first});
        }
        string res;
        for(const auto& it:m2){
            int times = it.first;
            for(int i=0; i < times; ++i){
                res.push_back(it.second);
            }
        }
        return res;
    }
};

int main(){
    string ss = "tree";
    auto p = make_unique<Solution>();
    string res = p->frequencySort(ss);
    cout << res << endl;
}
