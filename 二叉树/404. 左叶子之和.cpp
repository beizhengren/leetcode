
// 题中让求的时所有左叶子节点的和，不是左侧节点！！！
// 要明确左叶子节点的判断条件。左叶子节点只能由父节点判断，不能由自己判断。

// 这道题目要求左叶子之和，其实是比较绕的，因为不能判断本节点是不是左叶子节点。
// 此时就要通过节点的父节点来判断其左孩子是不是左叶子了

// Solution 1
// 迭代
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {return 0;}
        int sum = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();//front之后，一定要pop！
                if (node->left) {que.push(node->left);}
                if (node->right) {que.push(node->right);}
                // 注意”左叶子“节点的判断只能通过父节点来判断
                if (node->left
                    && node->left->left == nullptr
                    && node->left->right == nullptr){
                        sum += node->left->val;
                }
            }
        }

        return sum;
    }
};

// Solution 2
// 递归
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // 题中让求的时所有左叶子节点的和，不是左侧节点！！！
        if (root == nullptr) {return 0;}
        if (root->left && root->left->left == nullptr && root->left->right == nullptr){
            sum += root->left->val;
        }
        sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return sum;
    }
private:
    int sum = 0;
};

// Soltion 3
// 递归
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // 题中让求的时所有左叶子节点的和，不是左侧节点！！！
        if (root == nullptr) {return 0;}
        int sum = 0;
        sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        if (root->left && root->left->left == nullptr && root->left->right == nullptr){
            sum += root->left->val;
        }
        return sum;
    }
};
