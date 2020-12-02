class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){ return 0;}
        int slow = 0;
        int fast = 0;
        for (; fast < nums.size(); ++fast) {
            if ( nums[fast] != val) {
                nums[slow] = nums[fast];
                ++slow;
            }else{
                continue;
            }
        }
        return slow;
    }
};
