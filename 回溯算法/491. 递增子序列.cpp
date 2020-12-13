//Solution 1
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
private:
    void backtracking(const vector<int>& nums, int startIndex) {
        if (path.size()>=2) {
            result.push_back(path);
        }
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); ++i) {
        // 去重，用uset保存当前“树层”不同树枝选取的值情况。如果用过（即当前即将选取的元素已经在之前使用过）就跳到下一个树枝
        // 判断是否为上升序列，因为取back(),必须判断uset是否为空    
            if(uset.find(nums[i]) != uset.end() || (!path.empty() && nums[i] < path.back()) ) {continue;}
            
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> result;
    vector<int> path;
};

//Solution 2
//用数组代替unordered_set
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
private:
    void backtracking(const vector<int>& nums, int startIndex) {
        if (path.size()>=2) {
            result.push_back(path);
            //这里不能return，因为要继续遍历
        }
        bool uset[201]{false};
        for (int i = startIndex; i < nums.size(); ++i) {
        // 去重，用uset保存当前“树层”不同树枝选取的值情况。如果用过（即当前即将选取的元素已经在之前使用过）就跳到下一个树枝
        // 判断是否为上升序列，因为取back(),必须判断uset是否为空    
            if(uset[nums[i] + 100] == true || (!path.empty() && nums[i] < path.back()) ) {continue;}
            uset[nums[i] + 100] = true;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> result;
    vector<int> path;
};
