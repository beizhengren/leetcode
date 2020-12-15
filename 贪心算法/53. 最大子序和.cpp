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

//Solution 2
//贪心算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // result初始值为最小
        int result = std::numeric_limits<int>::min();
        // 当前的序列和
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            //1. 由于从i = 0开始，那么进来就要加nums[i]，这样才是第一个sum的初始值
            sum += nums[i];
            //2. 与result作比较，更新当前sum。
            // 此步一定在3之前，因为2要先用完当前sum（当前sum以及result都有可能是负的）
            // 3是根据当前的sum判断下一次是否sum初始化成0,
            if (sum > result) {
                result = sum;
            } 
            //3. 如果当前sum的值<=0，那么下一个i，就要从新计算sum，因此恢复sum = 0
            if (sum <= 0) {
                sum = 0;
            }
        }
        
        return result;
    }
};
