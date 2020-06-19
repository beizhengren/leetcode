class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};//freq[256]记录所有ASCII出现的频率
        int l = 0, r = -1;//逻辑是判断子串的下一个字符(s[r+1])，而初始时候子串为空。顾r=-1。
        int res = 0;
        
        while(l < s.size()){
            //r+1判断的是子串末尾的下一个字符
            if(r+1 < s.size() && freq[s[r+1]] == 0)//如果下一个字符和子串中的字符不重复
                freq[s[++r]]++;//r向后移动(++r),将子串末尾的下一个字符纳入子串,同时更新其出现的次数（+1）
            else//如果下一个字符和子串中的字符重复
                freq[s[l++]]--;//l向后移动(l++), 将子串首字符去掉,同时更新其出现的次数（-1）。
            res = max (res, r-l+1);//子串长度 = r-l+1, 和res比较，取较大者。
        }
        return res;
    }
};
