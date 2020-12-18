// Solution 1
// DFS
// 前序和后序都可以，中序在递归的方法不可以。因为在递归到root，交换左右孩子后会出现问题，详见Solution2解释。
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {return root;}
        // 实验证明 1 -> 2,3; 2,3->1 这两种方式都可以
        
        // 1.交换左右孩子
        swap(root->left, root->right);
        
        // 2.翻转以右孩子为根的 左子树
        invertTree(root->left);
        
        // 3.翻转以左孩子为根的 右子树
        invertTree(root->right);
        return root;
    }
};

// Solution 2
// DFS 迭代法（3种方法都能够实现。因为每次在stack中取指针，这些都是事先存好的。
// 即便中序遍历到树根，将树根左右孩子交换，然后再取pop的时候还是之前的”右孩子“，而不是交换后的右孩子（”也就是交换之前的左孩子“））
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {return root;}
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            if (stk.top()) {
                TreeNode* node = stk.top();
                stk.pop();
                // pre: m ->l -> r
                // post: l -> r -> m
                // mid: l -> mid -> r 
                // 注意：不管你以pre, post, mid顺序访问这棵说，都要交换左右孩子
                // 而 注释掉 swap && 将pre换成 m ->r ->l是错误的
                swap(node->right, node->left);
                if (node->right) {stk.push(node->right);}
                stk.push(node);
                stk.push(nullptr);
                if (node->left) {stk.push(node->left);}

            } else {
                stk.pop();
                TreeNode* node = stk.top();
                stk.pop();
            }
        }
        return root;
    }
};

// Solution 2.1
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {return root;}
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            if (stk.top()) {
                TreeNode* node = stk.top();
                stk.pop();
                // pre: m ->l -> r
                // post: l -> r -> m
                // mid: l -> mid -> r 
                if (node->right) {stk.push(node->right);}
                stk.push(node);
                stk.push(nullptr);
                if (node->left) {stk.push(node->left);}

            } else {
                stk.pop();
                TreeNode* node = stk.top();
                swap(node->right, node->left); //节点处理逻辑
                stk.pop();
            }
        }
        return root;
    }
};
// Solution 3
// BFS迭代法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {return root;}
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();

                swap(node->left, node->right);
                if (node->left) {que.push(node->left);}
                if (node->right){que.push(node->right);}
            }
        }
        return root;
    }
};
