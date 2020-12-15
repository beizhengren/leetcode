class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {return true;}
        // cover是从index = 0开始，能够覆盖的最大范围的位置
        int cover = 0;
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
