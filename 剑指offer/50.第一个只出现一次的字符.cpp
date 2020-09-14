//哈希
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        char map[256]{0};//局部变量初始化，key is c, value is times;
        for(int i = 0; i < str.size(); ++i){
            map[str[i]]++;
        }
        
        int res = -1;
        for(int i = 0; i < str.size(); ++i){
            if(map[str[i]] == 1) {res = i;break;}
        }
        return res;
    }
};
