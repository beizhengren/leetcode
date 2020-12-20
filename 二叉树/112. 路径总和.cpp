// Solution 1
// DFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return backtracking(root, sum);
    }
private:
    // 从 node 出发，判断是否存在路径，使和为target
    bool backtracking (TreeNode* node, int target) {
        // 如果节点为空，直接返回false
        if (node == nullptr) {return false;}
        // 如果是叶子节点，并且叶子节点的值==target（剩余的值），找到路径，返回true
        if (node->left == nullptr && node->right == nullptr && node->val == target) {return true;}
        int newTarget = target - node->val;
        bool existL = backtracking(node->left, newTarget);
        bool existR = backtracking(node->right, newTarget);
        return existL || existR;
    } 
};

// Solution 2
// DFS 清晰版
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return backtracking(root, sum);
    }
private:
    // 从 node 出发，判断是否存在路径，使和为target
    bool backtracking (TreeNode* node, int target) {
        // 如果节点为空，直接返回false
        if (node == nullptr) {return false;}
        // 中
        // 如果是叶子节点，并且叶子节点的值==target（剩余的值），找到路径，返回true
        if (node->left == nullptr && node->right == nullptr && node->val == target) {return true;}
        // 左
        if (node->left) {
            if (backtracking(node->left, target - node->val)){return true;}
        }
        // 右
        if (node->right) {
            if (backtracking(node->right, target - node->val)) {return true;}
        }
        return false;
    } 
};
