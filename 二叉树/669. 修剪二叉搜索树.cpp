// Solution 1
// DFS 
// 核心观点就是判断root->val 处于所给区间的哪个位置
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {return nullptr;}

        // 中
        // root->val ... [low, high]. 即root的val小于low，
        // 那么可能符合条件的节点必然在root的右子树中
        if (root->val < low) {  
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        // [low, high], ..., root->val
        if (root->val > high) {
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }

        // low <= root->val <= high, 左边和右边都有满足题意的节点
        // 左
        root->left = trimBST(root->left, low, high);
        // 右
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
