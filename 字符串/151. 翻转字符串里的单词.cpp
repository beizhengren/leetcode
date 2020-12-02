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
                continue;自己
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


//自己

class Solution {
public:
    string reverseWords(string s) {
        int slowIdx = 0;
        int fastIdx = 0;
        //1.消除前面空格, 如何保存去除之后的字符串。
        for (; fastIdx < s.size(); ++fastIdx) {
            if (s[fastIdx] == ' ') { continue; }
            else {break;}
        }
        //此时fastIdx 已经指向第一个不为 ' '的元素

        //2.去除中间重复空格 
        for(; fastIdx < s.size(); ++fastIdx) {
            // 后边用到了fastIdx - 1做下标
            if ( fastIdx - 1 > 0
             && s[fastIdx] == s[fastIdx - 1]
             && s[fastIdx] == ' ') {
                continue;
            }
            else {
                s[slowIdx] = s[fastIdx];
                ++slowIdx;
            }
        }
        //3.消除后面空格
        //上面操作完成之后有可能 slowIdx-1这个位置是空格
        //也有可能不是.
        //带下标运算的一定要检查边界，当前位置最小是0
        if(slowIdx - 1 > 0 && s[slowIdx-1] == ' ') { s.resize(slowIdx - 1);}
        else { s.resize(slowIdx);}//resize(个数)
        //4.反转单词
        reverseOneWord(s, 0, s.size()- 1);

        fastIdx = 0;
        slowIdx = 0;
        for( ; fastIdx < s.size(); ++fastIdx){
            if(s[fastIdx] == ' ') { 
                reverseOneWord(s, slowIdx, fastIdx - 1);
                slowIdx = fastIdx + 1;
            }else {
                continue;
            }
        }
        // 注意 跳出条件的时候是 fastIdx到达了字符串末尾
        // 最后一个空格之后的字符， 到末尾字符构成的字符串
        // 还没有进行反转
        reverseOneWord(s, slowIdx, fastIdx - 1);
        return s;
    }

private:
    void reverseOneWord(string& ss, int l, int r) {
        while(l < r){
            swap(ss[l], ss[r]);
            //注意变量的更新
            ++l;
            --r;
        }
    }
};



