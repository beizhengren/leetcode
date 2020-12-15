// Solution 1
// 动态规化
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 注意dp这个数组不是单调的，因此要比较每一个元素的值，选出最大的
        // dp[i]表示i之前（包括i）的最大连续子序列和
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            //两种情况：1.如果dp[i-1] < 0，那么dp[i] = nums[i];
            //2.如果dp[i-1] >= 0, 那么dp[i] = dp[i-1] + nums[i];
            dp[i] = max (dp[i-1] + nums[i],  nums[i]);
            // 更新result
            if (dp[i] > result) {
                result = dp[i];
            }
        }   
        return result;
    }
};
