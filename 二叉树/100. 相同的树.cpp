// Solution 1
// DFS 前序 m l r
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {return true;}
        else if (p == nullptr && q != nullptr) {return false;}
        else if (p != nullptr && q == nullptr) {return false;}
        else if (p->val != q->val) {return false;}
        else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};

// Solution 2
// 迭代 队列 成对儿入队， 什么序都不是， 只是用队列保存数据
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {return true;}
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while (!que.empty()) {
            TreeNode* nodeP = que.front(); que.pop();
            TreeNode* nodeQ = que.front(); que.pop();
            if (nodeP == nullptr && nodeQ == nullptr) {
                continue;
            }
            if (nodeP != nullptr && nodeQ == nullptr) {
                return false;
            }
            if (nodeP == nullptr && nodeQ != nullptr) {
                return false;
            }
            if (nodeP->val != nodeQ->val) {
                return false;
            } else {
                que.push(nodeP->left);
                que.push(nodeQ->left);
                que.push(nodeP->right);
                que.push(nodeQ->right);
            }
        }
        return true;
    }
};
