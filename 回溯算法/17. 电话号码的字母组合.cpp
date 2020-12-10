class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) { return result; }
        backtracking(digits, 0);
        return result;
    }

private:
    void backtracking(const string& digits, int startIdx) {
        if(startIdx == digits.size()) {
            result.push_back(path);
            return; //一定要 return
        }
        char ch = digits[startIdx];
        const string ss = letterMap[static_cast<int>(ch - '0')];
        //当前层有ss.size()种可能
        for (int i = 0; i < ss.size(); ++i) {
            path.push_back(ss[i]);
            //startIdx+1是下一层
            backtracking(digits, startIdx + 1);
            path.pop_back();
        }
    }
    string path;
    vector<string> result;
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz" // 9
    };

};
