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
