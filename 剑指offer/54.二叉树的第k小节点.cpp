/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        //要对给定函数传进来的参数都做边界考虑
        if(pRoot == nullptr || k == 0) return nullptr;
        int cnt = 0;
        helper(pRoot, k, cnt);
        return res;
    }
private:
    //BST的中序遍历是递增序列
    void helper(TreeNode* root, int k, int& cnt){
        if(root == nullptr)return;
        helper(root->left, k, cnt);
        
        ++cnt;
        if(cnt == k) {
            res = root;
            return;
        }
        if(cnt>k)return;
        
        helper(root->right, k, cnt);
    }
    TreeNode* res = nullptr;//成员变量一定要初始化！
};
