class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {return root;}
        // 实验证明 1 -> 2,3; 2,3->1 这两种方式都可以
        
        // 1.交换左右孩子
        swap(root->left, root->right);
        
        // 2.翻转以右孩子为根的 左子树
        invertTree(root->left);
        
        // 3.翻转以左孩子为根的 右子树
        invertTree(root->right);
        return root;
    }
};
