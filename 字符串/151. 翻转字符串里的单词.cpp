class Solution {
public:
    string reverseWords(string s) {
        //剔除字符串前部空格，中间重复空格，尾部空格
        removeExtraSpaces(s);
        // 翻转整个字符串
        swapK(s, 0, s.size()-1);

        int slowIdx = 0;
        int fastIdx = 0;
        for(; fastIdx < s.size(); ++fastIdx){
            if(s[fastIdx] == ' '){
                swapK(s, slowIdx, fastIdx - 1);
                slowIdx = fastIdx + 1;
            }else{
                continue;
            }
        }
        //处理尾端：
        //从slowIdx～s.size()-1都是字母。否则slowIdx = s.size().
        //不存在slowIdx指向最后一个元素为空格，因为上面对所有空格都处理过。
        if(slowIdx < s.size()){
            swapK(s, slowIdx, s.size()-1);
        }
        return s;
    }
private:
    void swapK(string& s, int l, int r){
        while (l < r) {
            swap(s[l], s[r]);
            ++l;
            --r;
        }
    }
    
    // 移除冗余空格：使用双指针（快慢指针法）O(n)的算法
    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
        // 去掉字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            // 去掉字符串中间部分的冗余空格
            if (fastIndex - 1 > 0
                    && s[fastIndex - 1] == s[fastIndex]
                    && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        //剔除尾部空格, 注意是slowIdx - 1.
        // 要么slowIdx == s.size(), 要么slowIdx所指向的元素是空格
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {
            // 重新设置字符串大小
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex);
        }
    }
};
