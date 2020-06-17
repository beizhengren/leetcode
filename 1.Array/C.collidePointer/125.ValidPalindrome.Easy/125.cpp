class Solution {
public:
    bool isPalindrome(string s) {
        //i < j, if i == j, represents true
        for(int i = 0, j = s.size()-1; i < j; i++, j--){
            //stripe no-alphanumeric
            //i < j is essential
            while(!isalnum(s[i]) && i < j){i++;}
            while(!isalnum(s[j]) && i < j){j--;}
            if(toupper(s[i]) == toupper(s[j])){continue;}
            else {return false;}
            
        }
        return true;
    }
};
