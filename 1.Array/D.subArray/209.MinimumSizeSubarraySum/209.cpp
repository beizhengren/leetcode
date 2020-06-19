class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = -1; // nums[l...r]为滑动窗口
        int sum = 0;//滑动窗口所有元素的和
        int res = nums.size() + 1;
        while(l < nums.size()){//l在数组范围内
            
            if(r + 1 < nums.size()  && sum < s){//r的范围在倒数第二个，因为后面逻辑有++r
                sum += nums[++r];//update sum and r
            }else{
                sum -= nums[l++];//update sum and l
            }
            //updated sum meets the condition
            if(sum >= s) res = min(res, r-l+1);//r < l 就是负的
        }
        
        if( res == nums.size() + 1){return 0;}
        return res;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = -1; // nums[l...r]为滑动窗口
        int sum = 0;//滑动窗口所有元素的和
        int res = nums.size() + 1;
        while(l < nums.size()){//l在数组范围内

            if(r < static_cast<int>(nums.size() - 1)  && sum < s){//r的范围在倒数第二个，因为后面逻辑有++r
                sum += nums[++r];//update sum and r
            }else{
                sum -= nums[l++];//update sum and l
            }
            //updated sum meets the condition
            if(sum >= s) res = min(res, r-l+1);//r < l 就是负的
        }

        if( res == nums.size() + 1){return 0;}
        return res;
    }
};
