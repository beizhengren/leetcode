// Solution 1
// DFS 允许空节点进入
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }

private: 
    TreeNode* build(vector<int>& nums, int beg, int end) {
        // 空节点
        if (beg > end) {return nullptr;}
        int maxValue = INT_MIN;
        int maxIdx = -1;
        for (int i = beg; i <= end; ++i) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxIdx = i;
            }
        }

        TreeNode* root = new TreeNode(maxValue);
        // beg == end也就是叶子节点,返回
        if (beg == end) {return root;}

        // 以maxIdx划分左右区间. 如果maxIdx == beg, 必然有leftEnd > leftBeg, 返回nullptr
        int leftBeg = beg;
        int leftEnd = maxIdx - 1;
        int rightBeg = maxIdx + 1;
        int rightEnd = end;

        root->left = build(nums, leftBeg, leftEnd);
        root->right = build(nums, rightBeg, rightEnd);
        return root;
    }
};

// Solution 2
// DFS 不允许空节点递归, 其实和1一样
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }

private: 
    TreeNode* build(vector<int>& nums, int beg, int end) {
        // 空节点
        if (beg > end) {return nullptr;}
        int maxValue = INT_MIN;
        int maxIdx = -1;
        for (int i = beg; i <= end; ++i) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxIdx = i;
            }
        }

        TreeNode* root = new TreeNode(maxValue);
        // beg == end也就是叶子节点,返回
        if (beg == end) {return root;}

        // 以maxIdx划分左右区间. 如果maxIdx == beg, 必然有leftEnd > leftBeg, 返回nullptr
        int leftBeg = beg;
        int leftEnd = maxIdx - 1;
        int rightBeg = maxIdx + 1;
        int rightEnd = end;
        if (leftBeg <= leftEnd)// 不允许空节点进入,但是构造的时候默认就有叶子节点是nullptr
            root->left = build(nums, leftBeg, leftEnd);
        if (rightBeg <= rightEnd)// 不允许空节点进入
            root->right = build(nums, rightBeg, rightEnd);
        return root;
    }
};
