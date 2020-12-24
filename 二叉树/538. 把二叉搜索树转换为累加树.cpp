// Solution 1
// DFS
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        // 递归终止条件
        if (root == nullptr) {return root;}
        // 右
        convertBST(root->right);
        // 中
        if (pre == nullptr) {
            root->val = root->val;
        }
        if (pre != nullptr) {
            root->val = root->val + pre->val;
        }
        pre = root;
        // 左
        convertBST(root->left);
        // 递归终止条件
        return root;
    }
private:
    TreeNode* pre = nullptr;
};
