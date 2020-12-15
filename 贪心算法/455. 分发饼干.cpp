//贪心
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        // i是饼干下标
        // j是胃口下标
        for (int i = s.size()-1, j = g.size()-1; i >= 0 && j>=0; --j) {
            if (s[i] >= g[j]) {
                --i;
                ++cnt;
            }else {}
        }
        return cnt;
    }
};
