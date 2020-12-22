// Solution 1
// DFS

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {return nullptr;}
        // 树t1不为空,t2为空,那么合并之后必然是t1
        if (t1 != nullptr && t2 == nullptr) {return t1;}
        if (t1 == nullptr && t2 != nullptr) {return t2;}
        if (t1 != nullptr && t2 != nullptr) {
            // 构造一棵树(也可以修改树t1的值,或者t2的值,这里新构造节点比较清晰)
           TreeNode* root = new TreeNode(t1->val + t2->val);
           root->left = mergeTrees(t1->left, t2->left);
           root->right = mergeTrees(t1->right, t2->right); 
           return root;
        }
        return nullptr;
    }
};
