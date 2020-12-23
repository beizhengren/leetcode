//Solution 3 迭代法
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 1. 创建节点
        // 2. 找到 位置
        // 3. 添加
        TreeNode* node = new TreeNode(val);

        if (root == nullptr) { return node;}
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        // BST 不用遍历整颗树, 只要根据输入值和节点之间的关系找到路径就可以了
        // 必然会为空,因为路径是一直向下延伸的,肯定会遇到空节点. 就在空节点出插入给定的节点
        while (cur != nullptr) {
            pre = cur;
            if (cur->val < val) {cur = cur->right;}
            // 注意这里必须是严格的if else关系, 否则会执行两次
            else if (cur->val > val) {cur = cur->left;}
        }

        // cur已经是nullptr了
        if (pre->val < val) {pre->right = node;}
        if (pre->val > val) {pre->left = node;}
        return root;
    }
};
