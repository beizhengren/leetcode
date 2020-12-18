// Solution 1
// 队列, 层序遍历

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {return 0;}
        int result = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) {que.push(node->left);}
                if (node->right) {que.push(node->right);}
            }
            ++result;
        }
        return result;
    }

};

// Solution 2
// 递归 void型返回值
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {return 0;}
        getMaxDepth(root, 0);
        return result;
    }

private:
    void getMaxDepth (TreeNode* node, int level) {
        if (node == nullptr) {return;}
        
        result = max(result, level + 1);
        getMaxDepth(node->left, level + 1);
        getMaxDepth(node->right, level + 1);
    }
    int result;
};

// Solution 3
// 递归 int型返回值
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //注释掉,简化. if (root == nullptr) {return 0;}
        return getMaxDepth(root);
    }
private:
    int getMaxDepth(TreeNode* node) {
        if (node == nullptr) {return 0;}
        int maxL = 1 + getMaxDepth(node->left);
        int maxR = 1 + getMaxDepth(node->right);
        return max(maxL, maxR);
    }
};
