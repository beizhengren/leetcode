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

// Solution 3
// 迭代 双栈 中序
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {return result;}
        stack<TreeNode*> stk;
        stack<string> pathStk;
        stk.push(root);
        pathStk.push(to_string(root->val));

        while (!stk.empty()) {
            if (stk.top()) {
                TreeNode* node = stk.top();
                stk.pop();
                string nodePath = pathStk.top();
                pathStk.pop();
                //pre: m l r
                if (node->right) {
                    stk.push(node->right);
                    pathStk.push(nodePath + "->" + to_string(node->right->val));
                }
                if (node->left) {
                    stk.push(node->left);
                    pathStk.push(nodePath + "->" + to_string(node->left->val));
                }
                stk.push(node);
                stk.push(nullptr);
                pathStk.push(nodePath);
            } else {
                stk.pop();
                TreeNode* node = stk.top();
                stk.pop();
                string nodePath = pathStk.top();
                pathStk.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    result.push_back(nodePath);
                }
            }
        }
        return result;
    }
private:
    vector<string> result;
};


// Solution 4
// BFS 双队列
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {return result;}
        queue<TreeNode*> que;
        queue<string> pathQue;//队列，用于保存que中的对应节点的路径(状态)
        que.push(root);
        pathQue.push(to_string(root->val));
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front(); 
                que.pop();//取出立即弹出
                string nodePath = pathQue.front();//取出当前节点的路径
                pathQue.pop();
                
                if (node->left) {
                    que.push(node->left);
                    // 将新的路径入队，对应当前的node->left
                    pathQue.push(nodePath + "->" + to_string(node->left->val));
                }
                if (node->right) {
                    que.push(node->right);
                    pathQue.push(nodePath + "->" + to_string(node->right->val));
                }
                if (node->left == nullptr && node->right == nullptr) {
                    result.push_back(nodePath);
                    continue;
                }
            }
        }
        return result;
    }
private:
    vector<string> result;
};
