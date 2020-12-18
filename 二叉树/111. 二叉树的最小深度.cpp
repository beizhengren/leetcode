// Solution 1
// 迭代 层序遍历
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {return 0;}
        int result = 0;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            ++result;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left == nullptr && node->right == nullptr) {return result;}
                if (node->left) {que.push(node->left);}
                if (node->right) {que.push(node->right);}
            }
        }
        return result;
    }
};

// Solution 2
// 递归 返回值类型int, 因此递归出口返回要么是0, 要么是1.
class Solution {
public:
    int minDepth(TreeNode* root) {
        return getMinDepth(root);
    }
private:
    int getMinDepth(TreeNode* root) {
        //  空节点
        if (root == nullptr) {return 0;}
        // 叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        // 非空非叶子节点
        int minL = INT_MAX;
        int minR = INT_MAX;
        // 只有孩子节点不问空, 才参与最小深度的计算.
        if (root->left) {minL = 1 + getMinDepth(root->left);}
        // 如果左子树为空，右子树不为空，说明最小深度是 1 + 右子树的深度。
        if (root->right) {minR = 1 + getMinDepth(root->right);}
        return min(minL, minR);
    }

};

// Solution 3
// 递归 返回值类型 void
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 这里一定要对 root == nullptr 做特殊处理, 因为result初值是 INT_MAX
        if (root == nullptr) {return 0;}
        result = INT_MAX;
        getMinDepth(root, 0);
        return result;
    }
private:
    void getMinDepth(TreeNode* root, int level) {
        if (root == nullptr) {return;}
        if (root->left == nullptr && root->right == nullptr) {
            result = min(result, 1 + level);
            return;
        }
        // 只有孩子节点不问空, 才参与最小深度的计算.
        if (root->left) {getMinDepth(root->left, level + 1);}
        // 如果左子树为空，右子树不为空，说明最小深度是 1 + 右子树的深度。
        if (root->right) {getMinDepth(root->right, level + 1);}
    }
    int result;
};
