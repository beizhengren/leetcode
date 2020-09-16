//https://blog.csdn.net/qq_27022241/article/details/80999255
//1.用set去除相同的结果
class Solution {
public:
    vector<string> Permutation(string str) 
    {
        if(!str.empty())
        {
            int length = str.size();
            PermutationRecursive(str, length, 0);
        }
        
        //扫描set中的内容,将结果导入vPermutationStr
        vPermutationStr.insert(vPermutationStr.end(),sPermutationStr.begin(), sPermutationStr.end());

        return vPermutationStr;
    }    
 
private:   
    //从index开始, str所有可能的排列保存到set中.
    void PermutationRecursive(string str, int length, int index)
    {
        if(index == length)
            sPermutationStr.insert(str);//保存交换后得到的字符串.
        
        for( int i = index; i < length; i++)
        {
            swap(str[i], str[index]);
            PermutationRecursive(str, length, index + 1);
        }
    }
 
    vector<string> vPermutationStr;
    set<string> sPermutationStr;//去除重复的结果
};


//2.相同的时候不交换
//https://zhuanlan.zhihu.com/p/58927978
class Solution {
public:
    vector<string> Permutation(string str) {
        //判断输入
        if(str.length() == 0){
            return result;
        }
        PermutationCore(str, 0);
        //对结果进行排序，因为可能存在重复，所以需要先排序，将重复的字符集合在一起
        sort(result.begin(), result.end());//实际实验,不做sort也可以通过测试用例
        return result;
    }    

    void PermutationCore(string str, int begin){
        //递归结束的条件：第一位和最后一位交换完成
        if(begin == str.length()){
            result.push_back(str);
            return;
        }
        for(int i = begin; i < str.length(); i++){
            //如果字符串相同，则不交换
            if(i != begin && str[i] == str[begin]){
                continue;
            }
            //位置交换
            swap(str[begin], str[i]);
            //递归调用，前面begin+1的位置不变，后面的字符串全排列
            PermutationCore(str, begin + 1);
        }
    }

private:
    vector<string> result;
};
