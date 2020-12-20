// DFS 前序
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {return result;}
        backtracking(root, sum);
        return result;
    }

private:
    void backtracking (TreeNode* node, int target) {
        if (node == nullptr) {return;}
        // 中 
        // 且是叶子节点才处理
        if (node->left == nullptr && node->right == nullptr && node->val == target) {
            path.push_back(node->val);//处理最后一个节点
            result.push_back(path);
            path.pop_back();//注意！！！回溯到上一个节点
            return;
        }
        // 左
        if (node->left) {
            path.push_back(node->val);
            backtracking(node->left, target - node->val);
            path.pop_back();
        }
        // 右
        if (node->right) {
            path.push_back(node->val);
            backtracking(node->right, target - node->val);
            path.pop_back();
        }
    }
    vector<vector<int>> result;
    vector<int> path;
};
