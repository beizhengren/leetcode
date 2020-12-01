//KMP算法
//T(n) = O(m + n)

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()){
            return 0;
        }
        if(haystack.empty() && !needle.empty()){
            return -1;
        }

        auto next = getNextArray(needle);

        int res = -1;
        int i = 0;
        int j = 0;
        for (; i < haystack.size(); ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j-1];
            }
            if (haystack[i] == needle[j]) {
                ++j;
            }
            if(j == needle.size()){
                res = i - needle.size() + 1;
                break;
            }
        }
        return res;
    }
private:
    //得到next数组
    vector<int> getNextArray (const string & needle){
        if (needle.empty()) {return {};}
        
        vector<int> next(needle.size(), 0);
        //i是前缀表达式的尾， j是后缀表达式的尾
        for(int i = 1, j = 0; i < needle.size(); ++i){
            while(j > 0 && needle[i] != needle[j]){
                j = next[j-1];
            }

            if(needle[i] == needle[j]){
                ++j;
            }
            //j 是[beg, ..., i]的最长前缀表达式的长度
            next[i] = j;
        }
        return next;
    }
};
