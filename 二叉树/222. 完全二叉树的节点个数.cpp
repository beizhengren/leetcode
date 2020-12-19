// Solution 1
// 递归：前序

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {return 0;}
        int sum = 1;
        sum += countNodes(root->left);
        sum += countNodes(root->right);
        return sum;
    }
};

// Solution 2
// 迭代 前序
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {return 0;}
        int sum = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            if (stk.top()) {
                TreeNode* node = stk.top();
                stk.pop();
                // pre: m -> l -> r
                if (node->right) {stk.push(node->right);}
                if (node->left) {stk.push(node->left);}
                stk.push(node);
                stk.push(nullptr);
            } else {
                stk.pop();
                TreeNode* node = stk.top();
                ++sum;
                stk.pop();
            }
        }
        return sum;
    }
};

// Solution 3
//迭代 层序
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {return 0;}
        int sum = 0;
        queue <TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                ++sum;
                if (node->left) {que.push(node->left);}
                if (node->right) {que.push(node->right);}
            }
        }
        return sum;
    }
};
