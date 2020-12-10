class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) {return result;}
        //sum初始为0， index是从candidates的0号开始
        backtracking(candidates, target, 0, 0);
        return result;
    }
private:
    void backtracking(vector<int>& candidates, int target, int sum, int index) {
        //没说连续，必须考虑>target的情况，否则会溢出
        if(sum > target) {
            return;
        }

        if (sum == target) {
            result.push_back(path);
            return;
        }

        //从包含index自己的位置开始向后取，自己前面的不算
        //如果是所有可能的“排列”，那么i应该从0开始。如[2,2,3] [2,3,3] ...
        for (int i = index; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            //可以包含自己，所以index从i开始
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<int> path;
    vector<vector<int> > result;
};
