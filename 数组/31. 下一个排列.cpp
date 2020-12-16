class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //得到下一个排列分为3步
        //1. 从后向前找第一个升序对(i-1, i), 即i-1和i构成了升序。（也就是说i...end是降序）
        //2. 从[i, ..., end]找到第一个比nums[i-1]大的位置j，交换i-1和j位置的元素。（交换后i...end仍然是降序）
        //3. 将[i ... end]的元素按照升序进行排序
        for (int i = nums.size()-1; i >= 1; --i) {
            if (nums[i] > nums[i-1]) {
                for (int j = nums.size()-1; j >= i; --j) {
                    if (nums[j] > nums[i-1]) {
                        swap (nums[j], nums[i-1]);
                        reverse(nums.begin() + i, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
