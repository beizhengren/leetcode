 /*
 1. 回溯法: 二叉树回溯的过程就是从低到上。 后序遍历就是天然的回溯过程，最先处理的一定是叶子节点。
 2. 有返回值的递归: 
 2.1 如果要搜索一条边，递归函数返回值不为空的时候，立刻返回，
 2.2 如果搜索整个树，直接用一个变量left、right接住返回值，这个left、right后序还有逻辑处理的需要，也就是后序遍历中处理中间节点的逻辑（也是回溯）
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归终止条件
        if (root == nullptr) {return nullptr;}
        if (root == p) {return p;}
        if (root == q) {return q;}

        // 左
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // 右
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 中 节点处理逻辑
        if (left != nullptr && right == nullptr) {return left;}
        if (right != nullptr && left == nullptr) {return right;}
        if (left != nullptr && right != nullptr) {return root;}
        return nullptr; //left == nullptr && right == nullptr
    }
};
