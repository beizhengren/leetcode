//using string member function
//find_first_of("range_String_serached", first_position_of_string_begin_to_search)
//find_last_of()
class Solution {
public:
    string reverseVowels(string s) {       
        for(int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if(i < j) swap(s[i], s[j]);
        }
        return s;
    }
};
