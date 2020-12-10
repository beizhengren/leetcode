// Solution 1
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        //假设有数组[0, 1, 2, ... 9]，那么index从1开始
        backtracking(k, n, 0, 1);
        return result;
    }
private:
    //从startIdx，包括startIdx 开始求满足题意的组合
    void backtracking (int totalNumbers, int target, int sum, int startIdx) {
        if (path.size() == totalNumbers) {
            if (sum == target) {
                result.push_back(path);
            }
            return;
        }
        
        for (int i = startIdx; i <= 9; ++i) {
            path.push_back(i);
            sum += i;
            backtracking(totalNumbers, target, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> result;
    vector<int> path;
};

// Solution 2 剪枝
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        //假设有数组[0, 1, 2, ... 9]，那么index从1开始
        backtracking(k, n, 0, 1);
        return result;
    }
private:
    //从startIdx，包括startIdx 开始求满足题意的组合
    void backtracking (int totalNumbers, int target, int sum, int startIdx) {
        if (path.size() == totalNumbers) {
            if (sum == target) {
                result.push_back(path);
            }
            return;
        }
        
        // 数组是排序的，因此可以直接进行剪枝
        for (int i = startIdx; i <= 9 && sum + i <= target; ++i) {
            path.push_back(i);
            sum += i;
            backtracking(totalNumbers, target, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> result;
    vector<int> path;
};
