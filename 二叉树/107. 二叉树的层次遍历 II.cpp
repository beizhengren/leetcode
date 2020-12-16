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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> layerResult;
        if (root == nullptr) {return result;}
        
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            // 注意每次（层）都要计算大小
            int size = que.size();
            // 每一层的结果清零
            layerResult.clear();
            for (int i = 0; i < size; ++i) {
                //注意队列的首是front
                auto node = que.front();
                que.pop();
                layerResult.push_back(node->val);
                if (node->left){que.push(node->left);}
                if (node->right){que.push(node->right);}
            }
            result.push_back(layerResult);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
