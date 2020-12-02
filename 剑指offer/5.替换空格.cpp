class Solution {
public:
    //从后向前
	void replaceSpace(char *str,int length) {
        if(str == nullptr || length <= 0) return;
        char* tailA = str;
        char* tailB = nullptr;
        int cntSpace = 0;
        //数空格个数
        while(*tailA!='\0'){
            if(*tailA == ' ') ++cntSpace;
            ++tailA;
        }
        tailB = tailA + 2 * cntSpace;//注意不能忘了乘以系数2
        
        while(tailA != tailB && tailA >= str && tailB >= str){
            if(*tailA != ' '){
                *tailB = *tailA;
            }else{
                *tailB = '0'; --tailB;
                *tailB = '2'; --tailB;
                *tailB = '%'; 
            }
            --tailA;
            --tailB;
        }
        return;
	}
};


class Solution {
public:
    string replaceSpace(string s) {
        size_t oldSize = s.size();
        size_t count = 0;
        for (int i = 0; i < oldSize; ++i) {
            // 注意条件是“==”
            if(s[i] == ' '){
                ++count;
            }
        }
        //“多“了 2 * count个
        s.resize(oldSize + 2 * count);
        size_t newSize = s.size();
        // 如果 i == j，跳出循环，后面的不用再遍历
        for (int i = newSize - 1, j = oldSize - 1; i > j; ) {
            if(s[j] == ' '){
                s[i] = '0';
                s[i-1] = '2';
                s[i-2] = '%';
                i-=3;
                --j;
            }else{
                s[i] = s[j];
                --i;
                --j;
            }
        }
        return s;
    }
};
