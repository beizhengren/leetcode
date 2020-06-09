///1. std::remove(iteratorBegin(), iteratorEnd(), removeVal)
///2. erase 擦除并destroy.这里是一次性删除。如果用循环，
//for(auto it = nums.begin(); it != nums.end(); ++it)
//每次循环都判断
///*it == val 然后erase，会有问题。因为erase之后nums.end()会变。
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};
