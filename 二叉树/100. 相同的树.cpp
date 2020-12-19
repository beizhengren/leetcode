// Solution 1
// DFS 前序 m l r
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {return true;}
        else if (p == nullptr && q != nullptr) {return false;}
        else if (p != nullptr && q == nullptr) {return false;}
        else if (p->val != q->val) {return false;}
        else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
