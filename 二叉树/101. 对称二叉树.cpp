class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {return true;}
        else {return compare(root->left, root->right);}
    }

private:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {return true;}
        else if (left == nullptr && right != nullptr) {return false;}
        else if (left != nullptr && right == nullptr) {return false;}
        // 当左右孩子都不为空的时候，需要先判断两个节点的值是否相等，再递归
        else if (left->val == right->val) {
            return compare(left->left, right->right) && compare(left->right, right->left);
        }else {
            return false;
        }
    }
};
