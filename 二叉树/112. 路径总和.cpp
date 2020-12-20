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

// Solution 3
// 迭代 前序
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {return false;}
        stack<TreeNode*> stk;
        stk.push(root);
        stack<int> stkSum;
        stkSum.push(root->val);
        while (!stk.empty()) {
            if (stk.top()) {
                TreeNode* node  = stk.top();
                stk.pop();
                int value = stkSum.top();
                stkSum.pop();
                // pre: m l r
                if (node->right) {
                    // 保存当前节点的状态（路径和）
                    stkSum.push(value + node->right->val);
                    stk.push(node->right);
                }

                if (node->left) {
                    stkSum.push(value + node->left->val);
                    stk.push(node->left);
                }
                stk.push(node);
                stk.push(nullptr);
                stkSum.push(value);
            } else {
                stk.pop();
                TreeNode* node = stk.top();
                stk.pop();
                int value = stkSum.top();
                stkSum.pop();
                if (node != nullptr 
                    && node->left == nullptr
                    && node->right == nullptr) {
                        if (value == sum) {
                            return true;
                        }
                }
            }
        }
        return false;
    }
};
