// Solution 1
// 递归 中序
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

// Solution 2
// 递归 中序 清晰版
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {return result;}
        backtracking(root);
        return result;
    }
private:
// 需要前序遍历，这样才方便让父节点指向孩子节点，找到对应的路径。
    void backtracking(TreeNode* node) {
        //if (node == nullptr) {return;} //递归终止条件
        //中
        path += to_string(node->val); // 操作：节点不为空，要将节点立即保存
        if (node->left == nullptr && node->right == nullptr) {//递归终止条件
            result.push_back(path);//终止处理逻辑
            return;
        }

        int oldSize = path.size(); //记录当前长度（状态）
        // 递归左子树
        if (node->left != nullptr) {
            path += ("->");//插入 "->"
            backtracking(node->left);//这里会保留左子树的信息
            path.resize(oldSize);//回溯到oldSize状态
        }
        // 递归右子树
        if (node->right != nullptr) {
            path += ("->");
            backtracking(node->right);
            path.resize(oldSize);
        }       
    }
    vector<string> result;
    string path;
};

