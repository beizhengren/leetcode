// Soluton 1
// 递归(不属于前中后的顺序)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {return true;}
        else {return compare(root->left, root->right);}
    }

private:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {return true;}
        else if (left == nullptr && right != nullptr) {return false;}
        else if (left != nullptr && right == nullptr) {return false;}
        // 当左右孩子都不为空的时候，需要先判断两个节点的值是否相等，再递归
        else if (left->val == right->val) {
            return compare(left->left, right->right) && compare(left->right, right->left);
        }else {
            return false;
        }
    }
};

// Solution 2
// 迭代:队列
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {return true;}
        queue<TreeNode*> que;
        //成对的push
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            int size = que.size();
            // size是节点个数,一共有size>>对儿, 只不过有的孩子是空节点.
            // for (int i = 0; i < (size>>1) ; ++i) { 可以删除
                // 1.取出当前一对儿节点
                TreeNode* leftNode = que.front(); que.pop();
                TreeNode* rightNode = que.front(); que.pop();
                
                // 2.对当前一对儿节点进行判断
                // 当前这对节点都为空,说明对称,可以继续判断
                if (leftNode == nullptr && rightNode == nullptr) {
                    continue;
                } 
                // 不可能同时为空的其他情况
                else if ( leftNode == nullptr || rightNode == nullptr || (leftNode->val != rightNode->val)) {
                    return false;
                } 
                else {
                    //注意这里push的顺序
                    que.push(leftNode->left);
                    que.push(rightNode->right);
                    que.push(leftNode->right);
                    que.push(rightNode->left);         
                }      
            //}
        }
        return true;
    }
};

// Solution 3
// 迭代 栈
// 和上面一样,只是用的是栈, front 改成 top
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {return true;}
        stack<TreeNode*> stk;
        //成对的push
        stk.push(root->left);
        stk.push(root->right);
        while (!stk.empty()) {
            int size = stk.size();
            // size是节点个数,一共有size>>对儿, 只不过有的孩子是空节点.
            // for (int i = 0; i < (size>>1) ; ++i) { 
                // 1.取出当前一对儿节点
                TreeNode* leftNode = stk.top(); stk.pop();
                TreeNode* rightNode = stk.top(); stk.pop();
                
                // 2.对当前一对儿节点进行判断
                // 当前这对节点都为空,说明对称,可以继续判断
                if (leftNode == nullptr && rightNode == nullptr) {
                    continue;
                } 
                // 不可能同时为空的其他情况
                else if ( leftNode == nullptr || rightNode == nullptr || (leftNode->val != rightNode->val)) {
                    return false;
                } 
                else {
                    //注意这里push的顺序
                    stk.push(leftNode->left);
                    stk.push(rightNode->right);
                    stk.push(leftNode->right);
                    stk.push(rightNode->left);         
                }      
            //}
        }
        return true;
    }
};
