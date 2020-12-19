class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {return result;}
        backtracking(root);
        return result;
    }
private:
    void backtracking(TreeNode* node) {
        if (node == nullptr) {return;} //递归终止条件

        path += to_string(node->val); // 操作
        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path);
            return;
        }

        int oldSize = path.size(); //记录当前长度（状态）

        path += ("->");//插入 "->"
        backtracking(node->left);//这里会保留左子树的信息
        path.resize(oldSize);//回溯到oldSize状态

        path += ("->");
        backtracking(node->right);
        path.resize(oldSize);

    }
    vector<string> result;
    string path;
};
