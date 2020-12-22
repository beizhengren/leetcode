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

// Solution 3
// DFS 前序
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        findBottomLeftValue(root, 0);
        return result;
    }
private:
    void findBottomLeftValue(TreeNode* node, int curLevel) {
        if (node == nullptr) {return;}
        // 中
        if (curLevel > maxLevel) {
            result = node->val;
            maxLevel = curLevel;//只在第一次(左子树)更新maxLevel
        }
        // 左
        // 注意!!!这里必须是curLevel + 1, 不能用maxLevel
        // 因为先递归左子树,更新maxLevel. 等递归右子树的时候有可能curLevel < maxLevel
        if (node->left) {
            findBottomLeftValue(node->left, curLevel + 1);
        }
        //右
        // 必须遍历右子树, 因为最大层(结果)有可能在右子树里
        if (node->right) {
            findBottomLeftValue(node->right, curLevel + 1);
        }
    }
    int result = 0;
    int maxLevel = INT_MIN;
};
