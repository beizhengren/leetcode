class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
private:
    void backtracking(const vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> result;
    vector<int>path;
};
