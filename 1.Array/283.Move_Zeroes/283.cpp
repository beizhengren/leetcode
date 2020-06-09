class Solution {
public:
    /*
    void moveZeroes(vector<int>& nums) {
       int k{0};
        for(size_t i = 0; i < nums.size(); ++i){
            if(nums[i] !=0 ){
                if(i > k){//i > k 说明i ~ k -1肯定是0
                    swap(nums[k], nums[i]);
                    k++;
                }
                else{
                    k++;
                }
                
            }
        }
    }
    */
///j 遍历整个数组（每次循环++）
///i 记录数组中第一个0的位置（只有满足条件才++，要么与非0交换过，要么本身就是非0）
    void moveZeroes(vector<int>& nums) {
        int i{0};
        for(size_t j = 0; j < nums.size(); ++j){
            if(nums[i] == 0){ 
                if(nums[j]!=0){
                    swap(nums[j], nums[i]); ++i;
                }
            }else{++i;}
        }
    }
};
