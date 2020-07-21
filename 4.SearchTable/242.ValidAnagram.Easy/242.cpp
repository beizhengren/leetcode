class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        map<char, int> m;
        int cnt = 0;
        int size = t.size();
        for(const auto & ss : s){
            m[ss]++;
        }
        
        for(int i = 0; i < t.size(); ++i){
            if(m[t[i]] != 0){
                cnt++;
                m[t[i]]--;
            }
        }
        if(cnt == size) return true;
        else return false;
    }
};
