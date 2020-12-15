class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int curDiff = 0;
        int preDiff = 0;
        int count = 1;//已经把nums.size() = 0或1的情况考虑进去了，因此初始情况就是元素为2，长度至少是1
        //i = 1，对应nums.size()=2
        for (int i = 1; i < nums.size(); ++i) {
            curDiff = nums[i] - nums[i-1];
            if (preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0) {
                preDiff = curDiff;
                ++count;
            }
        }
        return count;
    }
};
