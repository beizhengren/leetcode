/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {return result;}
        queue<TreeNode*> que;
        que.push(root);
        // 由于是从根节点所在层开始算的，因此这里不保存
        // 。。。result.emplace_back(root->val);

        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; ++i) {
                auto node = que.front();
                que.pop();

                if (node->left) {que.push(node->left);}     
                if (node->right) {que.push(node->right);}
                if (i == size - 1) {result.push_back(node->val);}
            }
        }
        return result;
    }

private:
    vector<int> result;
};
