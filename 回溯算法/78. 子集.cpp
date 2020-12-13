class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }

private:    
    void backtracking(const vector<int>& nums, int startIdx) {
        // 子集问题是遍历问题
        //遍历所有的节点，包括空
        result.push_back(path);

        // if(startIdx >= nums.size()) {return;}
        if(startIdx < nums.size()){
            for(int i = startIdx; i < nums.size(); ++i) {
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> result;
    vector<int> path;
};
