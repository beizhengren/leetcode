

//Solution 2 剪枝

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) { return result;}
        used.resize(candidates.size());
        for (int i = 0; i < used.size(); ++i) {
            used[i] = false;
        }

        // 首先把给candidates排序，让其相同的元素都挨在一起。否则无法去重。
        // 然后，因为有序，后边可以剪枝
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
private:
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {

        if (sum == target) {
            result.push_back(path);
            return;
        }     

        // sum + candidates[i] <= target 剪枝
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) {
                continue;
            }
            used[i] = true;
            path.push_back(candidates[i]);
            sum += candidates[i];
            // 和39.组合总和的区别1：这里是i+1，每个数字在每个组合中只能使用一次
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
            used[i] = false;
        }
    }
    vector<bool> used;
    vector<int> path;
    vector<vector<int> >result;
};
