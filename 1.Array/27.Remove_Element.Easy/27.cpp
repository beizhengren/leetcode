///1. std::remove(iteratorBegin(), iteratorEnd(), removeVal)
///2. erase 擦除并destroy.这里是一次性删除。如果用循环，
//for(auto it = nums.begin(); it != nums.end(); ++it)
//每次循环都判断
///*it == val 然后erase，会有问题。因为erase之后nums.end()会变,
///可能出现it 比新的nums.end()大的情况，这样就在下次循环访问的时候发生错误。
///改成it < nums.end()可以通过，但是标准的iterator不支持<运算，可能是因为
///venctor才会成立.
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};
