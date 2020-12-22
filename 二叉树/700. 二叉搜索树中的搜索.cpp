// Solution 1
// DFS 
// BST 的递归 可以根据大小顺序来进行，不需要回溯
// 当然，如果用普通二叉树回溯也可以
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || val == root->val) {return root;}
        if (val < root->val) {return searchBST(root->left, val);}
        if (val > root->val) {return searchBST(root->right, val);}
        // 没有找到就返回nullptr
        return nullptr;
    }
};

//Solution 2
// 迭代 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // root 本身就是一个临时变量
        // BST遍历不需要回溯，因为是有序的路线可以按照大小顺序直接找到
        while(root != nullptr) {
            if (val < root->val) {root = root->left;}
            else if (val > root->val) {root = root->right;}
            else {return root;}
        }
        return nullptr;
    }
};
