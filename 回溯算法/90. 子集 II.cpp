class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        //用used去重必须排序！！！
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }
private:
    void backtracking(const vector<int>& nums, int startIndex, vector<bool>& used) {
        result.push_back(path);
        
        if (startIndex >= nums.size()) {return;}
        for (int i = startIndex; i < nums.size(); ++i) {
            // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 而我们要对同一树层使用过的元素进行跳过
            if(i > 0 && used[i-1] == false && nums[i-1] == nums[i]) {continue;}

            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, i + 1, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> result;
    vector<int>path;
};
