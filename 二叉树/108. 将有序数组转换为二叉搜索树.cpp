// Solution 1
// DFS
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        return helper(nums, 0, nums.size() - 1, root);
    }
private:
    TreeNode* helper(vector<int>& nums, int beg, int end, TreeNode* cur) {
        if (beg > end) {return nullptr;}

        int mid = beg + ((end - beg) >> 1);
        // 注意这里构造节点的时候的值是nums[mid]
        cur = new TreeNode (nums[mid]);
        cur->left = helper(nums, beg, mid - 1, cur->left);
        cur->right = helper(nums, mid + 1, end, cur->right);
        return cur;
    }
};
