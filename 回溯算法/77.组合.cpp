class Solution {

public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // 可以不写
        path.clear();   // 可以不写
        //根据题意：startIdx 从1开始，取到n
        backtracking(n, k, 1);
        return result;
    }

private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果

    //从startIdx，闭区间[startIdx, stratIdx + 1，...] 开始搜索，满足条件的所有组合
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) { 
            result.push_back(path); 
            return;
        }
        //注意是<=n，闭区间
        for (int i = startIndex; i <= n; ++i) {
            path.push_back(i);
            //
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }    
};
