
// Solution 1
// 用O(N)的额外空间
class Solution {
public:
    //BST 按照中序遍历必然是从小到大的
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {return true;}
        traversal(root);
        for (int i = 0; i < vec.size(); ++i) {
            //如果有一个不满足条件就返回false；
            if (i > 0 && vec[i] <= vec[i-1]) {
                return false;
            }
        }
        return true;
    }
private:
    void traversal(TreeNode* node) {
        if (node == nullptr) {return;}
        traversal(node->left);
        vec.push_back(node->val);
        traversal(node->right);
    }
    vector<int> vec;
};
