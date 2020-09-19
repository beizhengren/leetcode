//哈希
//给的字符串是按字母顺序的，因此从小到大依次扫描，就是和字符串中的顺序相同。
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        unsigned int map[256]{0};//局部变量初始化，key is c, value is times[0~10000];
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
