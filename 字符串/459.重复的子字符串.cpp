class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.empty()) {return false;}

        auto next = getNextArray(s);
        int len = next[next.size() - 1];
        //注意一定要判断不等于0
        if(len != 0 && s.size() % (s.size() - len) == 0){
            return true;
        }else{
            return false;
        }
        
    }

    vector<int> getNextArray (const string& s){
        if(s.size() == 0) { return {};}
        vector<int> next(s.size(), 0);
        int i = 1;
        int j = 0;
        for ( ; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j-1];
            }
            if (s[i] == s[j]) {
                ++j;
                next[i] = j;
            }
        }
        return next;
    }
};
