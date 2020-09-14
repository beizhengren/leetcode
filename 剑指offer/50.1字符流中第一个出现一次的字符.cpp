class Solution
{
public:
    Solution(){
        for(int i = 0; i < 256; ++i){
            map[i]= -1;
        }
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
         if(map[ch] == -1){
             map[ch] = idx;
         }
         else if(map[ch] >= 0){//这两个必须是互斥的，因为上一个分支改变了map[ch] 
             map[ch] = -2;
         }
        ++idx;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {    
        char res = '#';
        int minIdx = numeric_limits<int>::max();
        for(int ch = 0; ch < 256; ++ch){
            if(map[ch] >= 0 && map[ch] < minIdx){//必须map[ch]>=0才能比较
                minIdx = map[ch];
                res = (char)ch;
            }
        }
        return res;
    }
private:
    //定义map，c 为key，256种情况，
    //value >= 0表示第一次出现的时候位置
    //value == -1表示没有出现
    //value == -2表示出现>1次
    int map[256];    // int map[256]{-1};错误的初始化.只能初始化成1.
    int idx = 0;//记录当前insert元素的idx，
};
