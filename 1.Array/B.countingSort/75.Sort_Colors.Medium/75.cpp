//solution 1
//最直截了当的方式，没有任何计数含量。
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0{0}, cnt1{0}, cnt2{0};
        for(auto n:nums){
            switch(n){
                case 0: cnt0++; break;
                case 1: cnt1++; break;
                case 2: cnt2++; break;
            }
        }
        for(int i = 0; i < cnt0; ++i){
            nums[i] = 0;
        }
        for(int i = cnt0; i < cnt0 + cnt1; ++i){
            nums[i] = 1;
        }
        for(int i = cnt0 + cnt1; i < cnt0 + cnt1 + cnt2; ++i){
            nums[i] = 2;
        }
    }
};

//solution 2
//
//class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1; //nums[0 ... zero] == 0
        int two = nums.size(); //nums[two ... n-1] ==2
        //i represet current value; nums[zero+1, i-1] == 1
        for(int i = 0; i < two;){
            //the second interval complying the condition, i++;
            if (nums[i] == 1){
                i++;
            }
            else if(nums[i] == 2)
                //the third interval insert a element, so --two.
                swap(nums[i], nums[--two]);
            else {//nums[i] == 0
                assert(nums[i] == 0);
                //the first inerval insert a element, so ++zero, i++.
                swap(nums[++zero], nums[i++]);
            }
        }
    }
};
