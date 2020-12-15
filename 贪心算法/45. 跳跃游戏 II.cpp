// Solution 1
class Solution {
public:
    int jump(vector<int>& nums) {
        int curMaxEndIdx = 0;
        int nextMaxEndIdx = 0;
        int count = 0;
        //当前元素下标是i，其对应的最大范围元素的下标是curMaxEndIdx
        //curMaxEndIdx必须小于末尾元素下标，然后进行遍历
        for (int i = 0; i <= curMaxEndIdx && curMaxEndIdx < nums.size()-1; ++i) {
            //每次更新下一次能够到达的最大范围对应的下标
            nextMaxEndIdx = max(nextMaxEndIdx, i + nums[i]);
            //如果i == curMaxEndIdx,即访问到当前能够访问的最大元素下标
            if (i == curMaxEndIdx) {
                if (curMaxEndIdx != nums.size() - 1) {
                    //更新
                    curMaxEndIdx = nextMaxEndIdx;
                    //关键点：主要看是什么时候更新次数
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};

// Solution 2
// 对Solution的简化
class Solution {
public:
    int jump(vector<int>& nums) {
        int curMaxEndIdx = 0;
        int nextMaxEndIdx = 0;
        int count = 0;
        //当前元素下标是i，其对应的最大范围元素的下标是curMaxEndIdx
        //curMaxEndIdx必须小于末尾元素下标，然后进行遍历
        for (int i = 0; i <= curMaxEndIdx && curMaxEndIdx < nums.size()-1; ++i) {
            //每次更新下一次能够到达的最大范围对应的下标
            nextMaxEndIdx = max(nextMaxEndIdx, i + nums[i]);
            //如果i == curMaxEndIdx,即访问到当前能够访问的最大元素下标
            if (i == curMaxEndIdx) {               
                //更新
                curMaxEndIdx = nextMaxEndIdx;
                //关键点：主要看是什么时候更新次数
                count++;
            }
        }
        return count;
    }
};
