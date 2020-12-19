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
    // 确定单层递归的逻辑：先求它的左子树的深度，再求的右子树的深度，最后取左右深度最大的数值 再+1 
    //（加1是因为算上当前中间节点）就是目前节点为根节点的树的深度。
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);       // 左
        int rightDepth = getDepth(node->right);     // 右
        int depth = 1 + max(leftDepth, rightDepth); // 中
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};
