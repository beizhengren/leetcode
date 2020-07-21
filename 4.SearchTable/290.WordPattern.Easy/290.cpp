class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream strin(str);
        string substring;
        vector<string> vs;
        map<char, string> mcs;
        map<string, char> msc;

        while (strin >> substring) {
            vs.emplace_back(substring);
        }

        if (vs.size() != pattern.size()) return false;
        for (int i = 0; i < vs.size(); ++i) {
            if (msc[vs[i]] == 0 && mcs[pattern[i]] == "") {
                mcs[pattern[i]] = vs[i];
                msc[vs[i]] = pattern[i];
                continue;
            }
            //pattern is standard
            //if key "vs[i]" of msc don't exist,
            //then msc[vs[i]] = 0 whose value is not equals to pattern[i].
            //return false;
            if (msc[vs[i]] != pattern[i]) { return false; }
        }
        return true;
    }
};
