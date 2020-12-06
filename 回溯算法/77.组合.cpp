//方法1
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


//方法2：剪枝
class Solution {

public:
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        resOne.clear();
        backtracking(n, k, 1);
        return res;
    }

private:
    //从startIdx开始的所有组合
    void backtracking(int n, int k, int startIdx) {
        if (resOne.size() == k) {
            res.push_back(resOne);            
            return;
        }
        
        //剪枝：剩余元素的个数n - i + 1 应该大于等于 还差的个数 k - resOne.size()
        for (int i = startIdx;  n - i + 1 >=  k - resOne.size(); ++i) {
            resOne.push_back(i);
            backtracking(n, k, i + 1);
            resOne.pop_back();
        }
    }

    vector<vector<int>> res;
    vector<int> resOne;
};
