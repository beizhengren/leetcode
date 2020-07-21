//
// Created by wyz on 20-7-21.
//
#include <unordered_map>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            if(m.find(target - nums[i])!= m.end()){
                return {i, m[target -nums[i]]};
            }
            m.insert({nums[i], i});
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto p = make_unique<Solution>();
    auto res = p->twoSum(nums, target);
    for(auto it : res){
        cout << it << endl;
    }
}
