class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {return true;}
        // cover是从index = 0开始，能够覆盖的最大范围的位置
        int cover = 0;
        //注意，这里的cover是可变的，是能都到达的最大的位置
        //++i，每次访问当前元素后都继续访问直到cover
        for (int i = 0; i <= cover; ++i) {
            // cover = 当前位置 + 可以跳跃最大范围，
            // 比如i = 0， nums[0] = 3, 那么cover = 0 + nums[i] = 3(位置)
            // 始终保持cover是最大的
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size()-1) {
                return true;
            }
        }
        return false;
    }
};
