// Solution 1

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {return 0;}
        traversal(root);
        return minValue;
    }
private:
    void traversal(TreeNode* root) {
        // 终止条件
        if (root == nullptr) {return;}
        // 左
        traversal(root->left);
        // 中
        if (pre != nullptr && root->val - pre->val < minValue) {
            minValue = root->val - pre->val;
        }
        pre = root;
        // 右
        traversal(root->right);
    }
    TreeNode* pre = nullptr;
    int minValue = INT_MAX;
};


// Solution 2
// 迭代 pre节点
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {return 0;}
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            if (stk.top()) {
                TreeNode* node = stk.top();
                stk.pop();
                //mid: l m r
                if (node->right) {stk.push(node->right);}
                stk.push(node);
                stk.push(nullptr);
                if (node->left) {stk.push(node->left);}

            } else {
                stk.pop();
                TreeNode* node = stk.top();
                stk.pop();
                
                if (pre != nullptr && node->val - pre->val < minValue) {
                    minValue = node->val - pre->val;
                }
                pre = node;
            }
        }
        return minValue;
    }
private:
    
    TreeNode* pre = nullptr;
    int minValue = INT_MAX;
};
