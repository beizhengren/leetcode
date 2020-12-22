class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {return true;}
        // 左子树最大深度
        int maxL = getMaxLen(root->left);
        // 右子树最大深度
        int maxR = getMaxLen(root->right);
        // 如果左右子树深度 > 1,不满足条件 返回false
        if (maxL - maxR > 1 || maxR - maxL > 1) {return false;}
        // 如果左右子树深度 <= 1, 那么就要递归判断左右子树是不是满足条件
        else {return isBalanced(root->left) && isBalanced(root->right);}
    }
    // 求当前以node为根的二叉树的最大深度
    int getMaxLen (TreeNode* node) {
        if (node == nullptr) {return 0;}
        return 1 + max (getMaxLen(node->left), getMaxLen(node->right));
    }
};
