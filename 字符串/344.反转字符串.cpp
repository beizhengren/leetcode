class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0 ;
        int r = s.size()-1;
        while (l < r) {
            swap(s[l], s[r]);
            ++l;
            --r;
        } 
    }
private:
    void swap(char& s1, char& s2){
        auto tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
};
