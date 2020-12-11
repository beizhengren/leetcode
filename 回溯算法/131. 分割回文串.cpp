class Solution {
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
private:
    void backtracking(const string& s, int startIdx) {
        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
        if (startIdx == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startIdx; i < s.size(); ++i) {
            // 是回文子串, 才做切割，并赋值给新的string，这样性能更好
            if (isPalindrome(s, startIdx, i)) {
                string ss = s.substr(startIdx, i - startIdx + 1);//切割： 获取[startIndex,i]在s中的子串
                path.push_back(ss);
                backtracking(s, i + 1);// 寻找i+1为起始位置的子串
                path.pop_back();// 回溯过程，弹出本次已经填在的子串
            }
            else { // 不是回文，跳过
                continue;
            }
            
        }
    }

    bool isPalindrome (const string& s, int l, int r) {
        while (l<=r) {
            if (s[l] == s[r]) {
                ++l;
                --r;
                continue;
            }
            else { return false;}
        }
        return true;
    }

    vector<vector<string>> result;
    vector<string> path;  // 放已经回文的子串
};
