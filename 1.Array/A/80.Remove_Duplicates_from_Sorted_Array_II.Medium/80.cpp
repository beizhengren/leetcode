///solution 1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	///两个循环变量。
	//count记录题意中的相对重复的元素个数
	//count_inter记录的绝对重复元素个数
	//count_inter = 2的时候，说明绝对重复元素次数达到2次（共3个元素），count++
        int count{0}, count_inter{0};
        for(int i = 1; i < nums.size(); ++i){
            
            if(nums[i] == nums[i-1]){
                count_inter++;
		//当前元素和上一个元素相等，就要往前挪，
		//因为如果count!=0上一个元素i-1已经被复制到i-1-count位置，
		//这时候i-1只是之前保留下的值。因此要挪动i到i-count
                if(count_inter == 1){nums[i-count] = nums[i];}
                if(count_inter >= 2 ){count++;}    
            }
            else{
		///不相等，count_inter要清零，从新计数
                count_inter = 0;
		//挪动
                nums[i-count] = nums[i];
            }           
        }
        return nums.size() - count;
    }
};

///solution 2
// i repersents the eventually vector size, point the next position of the last element
//when i < 2, there are 2 elements at most, ethier same or not, complying with problem. And move i point next position of the last element of current new vector.
//It assure that the first pair of "two elements"

///when i >= 2, according to  the cond. n > nums[i-2]
// nums[i-2] and nums[i-1] is a pair of elements, and they are either equal or different.
//nums[i-2] is the first element of current pair.
//nums[i-1] can not be the compartor
//
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}

///k duplicates
int removeDuplicates(vector<int>& nums, int k) {
    int i = 0;
    for (int n : nums)
        if (i < k || n > nums[i-k])
            nums[i++] = n;
    return i;
}

