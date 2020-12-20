// BFS
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) {return 0;}
        queue <TreeNode*> que;
        que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) {que.push(node->left);}
                if (node->right) {que.push(node->right);}
                if (i == 0) { result = node->val;}
            }
        }
        return result;
    }
};

// Solution 2
// DFS 前序
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        result = 0;
        maxLevel = INT_MIN;
        dfs(root, 0);
        return result;
    }
private:
    // 1.求最后一层， 需要用个全局变量来记录最大层，并在满足条件下更新
    // 2.求最左侧节点，必然用前序
    void dfs (TreeNode* node, int level) {
        if (node == nullptr) {return;}
        // 中
        if (level > maxLevel) {
            maxLevel = level; // 必须更新maxLevel
            result = node->val;
        }
        // 左
        if (node->left) {
            ++level;
            dfs(node->left, level);
            --level;
        }
        // 右
        if (node->right) {
            ++level;
            dfs(node->right, level);
            --level;
        }
    }
    int result;
    int maxLevel;
};
