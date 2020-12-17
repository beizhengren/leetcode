/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Solution 1
// BFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {return result;}

        queue <TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            // 元素有可能有负数
            int maxValue = std::numeric_limits<int>::min(); 

            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (maxValue < node->val) {maxValue = node->val;}
                if (node->left) {que.push(node->left);}
                if (node->right) {que.push(node->right);}
            }
            result.emplace_back(maxValue);
        }
        return result;
    }
};

// Solution 2
// DFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {return result;}
        dfs (root, 0);
        return result;
    }
private:
    void dfs (TreeNode* node, int level) {
        if (node == nullptr) {return;}
        if (level == result.size()) {
            result.emplace_back(INT_MIN);
        }
        if (node->val > result[level]) {
            result[level] = node->val;
        }
        if (node->left) {dfs(node->left, level + 1);}
        if (node->right) {dfs(node->right, level + 1);}
    }

    vector<int> result;
};
