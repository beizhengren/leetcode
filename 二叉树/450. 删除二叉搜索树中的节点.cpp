// Solution 1

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 一, 没找到key，返回空
        if (root == nullptr) {return nullptr;}
        //　二，找到key　root->val == key
        // 1.删除节点的左右孩子均为空，删除节点，返回空
        // 2.删除节点的左孩子为空，返回删除节点的右孩子
        // 3.删除节点的右孩子为空，返回删除节点的左孩子
        // 4.删除节点左右孩子都不为空，那么将删除节点的左孩子（左子树的根节点）
        // 放到删除节点的右子树的最左边的节点的左孩子上，然后返回删除节点的右孩子
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            if (root->left == nullptr && root->right != nullptr) {
                auto res = root->right;
                delete root;
                return res;
            }
            if (root->left != nullptr && root->right == nullptr) {
                auto res = root->left;
                delete root;
                return res;
            }
            if (root->left && root->right) {
                TreeNode* cur = root->right;
                while( cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                auto res = root->right;
                delete root;
                return res;
                // return cur;///!!!!错，这里cur已经变了！！！
            }
        }
        if (root->val > key) { root->left = deleteNode(root->left, key);}
        if (root->val < key) { root->right = deleteNode(root->right, key);}
        return root;
    }
};
