// Solution 1
// DFS

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {return nullptr;}
        // 树t1不为空,t2为空,那么合并之后必然是t1
        if (t1 != nullptr && t2 == nullptr) {return t1;}
        if (t1 == nullptr && t2 != nullptr) {return t2;}
        if (t1 != nullptr && t2 != nullptr) {
            // 构造一棵树(也可以修改树t1的值,或者t2的值,这里新构造节点比较清晰)
           TreeNode* root = new TreeNode(t1->val + t2->val);
           root->left = mergeTrees(t1->left, t2->left);
           root->right = mergeTrees(t1->right, t2->right); 
           return root;
        }
        return nullptr;
    }
};


// Solution 2
// 迭代 双队列
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {return t2;}
        if (t2 == nullptr) {return t1;}
        //经过上面两句，这里保证t1和t2都不为空
        queue<TreeNode*> que;
        que.push(t1);
        que.push(t2);
        // 由于需要对queue中的节点指针的值进行修改，所以需要用二级指针修改一级指针（节点指针）
        // 或者保存TreeNode*&，但是编译通不过
        queue<TreeNode**>que2;
        // 构造根节点
        TreeNode* root = nullptr;
        que2.push(&root);
        while (!que.empty()) {
            // 拿到两个树的对应节点
            TreeNode* node1 = que.front();
            que.pop();
            TreeNode* node2 = que.front();
            que.pop();
            // 拿到根节点的地址
            // 由于后面要修改根节点，所以这里必须是二级指针，
            // 否则，修改的只是一个临时变量，对构造的树不起作用。
            TreeNode** pNode = que2.front();
            que2.pop();
            // 注意：更新根节点的值。
            int val = node1->val + node2->val;
            *pNode = new TreeNode(val);

            if (node1->left == nullptr && node2->left == nullptr) {}
            if (node1->right == nullptr && node2->right == nullptr) {}
            if (node1->left != nullptr && node2->left == nullptr) { 
                (*pNode)->left = node1->left;
            }
            if (node1->right != nullptr && node2->right == nullptr) {
                (*pNode)->right = node1->right;
            }
            if (node1->left == nullptr && node2->left != nullptr) {
                (*pNode)->left = node2->left;
            }
            if (node1->right == nullptr && node2->right != nullptr) {
                (*pNode)->right = node2->right;
            }
            if (node1->left && node2->left) {
                que.push(node1->left);
                que.push(node2->left);
                // 这里保存的是左子树的地址，即指针的指针。
                que2.push(&(*pNode)->left);
            }
            if (node1->right && node2->right){
                que.push(node1->right);
                que.push(node2->right);
                que2.push(&(*pNode)->right);
            }

        }
        return root;
    }
};
