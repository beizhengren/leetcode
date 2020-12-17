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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == nullptr) {return result;}

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            double ave = 0.0f;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                ave += static_cast<double>(node->val);

                if (node->left) {que.push(node->left);}
                if (node->right) {que.push(node->right);}
            }
            ave /= size;
            result.emplace_back(ave);
        }
        return result;
    }
};
