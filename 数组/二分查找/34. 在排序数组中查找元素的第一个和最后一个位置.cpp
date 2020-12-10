// 由于循环条件是 l <= r, 即判断闭区间[l, r]
// 那么跳出的时候，就是l > r

// 1.target是数组元素
// [3, 4, 5] 如果target = 4.
// 返回左边界“l”的前一个状态一定是l,r同时指向元素3，然后l = mid + 1，即最后返回l = 1；
// 返回右边界“r”的前一个状态一定是l,r同时指向元素5，然后r = mid - 1, 即最后返回r = 1;

// 2.1. target不是数组元素，且比所有元素都小
// [3, 4, 5] 如果target = 2.
// 返回左边界“l”的前一个状态一定是l,r同时指向元素3，然后r = mid - 1, l不动, 最后返回l = 0；
// 返回右边界“r”的前一个状态也是l,r同时指向元素3，然后 r = mid - 1, 最后返回r = -1;
// 可以看出 r < l, 不是有效区间

// 2.2 target不是数组元素，且比所有元素都大
// [3, 4, 5] 如果target = 6.
// 返回左边界“l"的前一个状态一定是l,r同时指向元素5，然后l = mid + 1, 即最后返回l = 3；
// 返回右边界”r“的前一个状态一定是l,r同时指向元素5，然后l = mid + 1, r不动, 即最后返回 r = 2；

// 3. target不是数组元素，且大小在数组范围内
// [3,6,7] 如果target = 5.
// 返回左边界”l“的前一个状态一定是l,r同时指向元素3，然后l = mid + 1, 即最后返回l = 1；
// 返回右边界”r“的前一个状态一定是l,r同时指向元素3，然后l = mid + 1，r不动，即返回r = 0；
// 可以看出 r < l, 不是有效区间

//综上，对于2.1，2.2，3这三种情况，都是r < l不是有效区间。
//只有情况1，即r >= l的时候有效。故返回之前要判断r和l的关系。

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // if(nums.empty()) { return {-1, -1};}
        int l = findLeft(nums, target);
        int r = findRight(nums, target);
        if(r < l) { return {-1, -1};}
        return {l, r};
    }
private:
    // 寻找左边界
    int findLeft(vector<int> & nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + ((r-l)>>1);
            if (target <= nums[mid]) {
                r = mid - 1;
            } else if (target > nums[mid]) {
                l = mid + 1;
            }
        }
        return l;
    }
    
    // 寻找右边界
    int findRight(vector<int> & nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        while (l<=r) {
            int mid = l + ((r-l)>>1);
            if (target < nums[mid]) {
                r = mid - 1;
            } else if (target >= nums[mid]){
                l = mid + 1;
            }
        }
        return r;
    }
};
