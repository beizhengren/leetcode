// Solution 1
// DFS 中序遍历
/*
和二叉树：公共祖先问题不同，普通二叉树求最近公共祖先需要使用回溯，从底向上来查找，二叉搜索树就不用了，因为搜索树有序（相当于自带方向），那么只要从上向下遍历就可以了。
那么我们可以采用前序遍历（其实这里没有中节点的处理逻辑，遍历顺序无所谓了）。
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == root || q == root) {return root;}
        if (p->val < root->val && q->val > root->val || q->val < root->val && p->val > root->val) {return root;}
        if (p->val < root->val && q->val < root->val) {return lowestCommonAncestor(root->left, p, q);}
        if (p->val > root->val && q->val > root->val) {return lowestCommonAncestor(root->right, p, q);}
        return nullptr;
    }
};

// Solution 2
// 迭代法

// 题目中保证了p q都不为nullptr
// BST与普通二叉树区别, 这里没有重复元素,且元素都是有序的.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {return root;}
        TreeNode* result = nullptr;
        while (root != nullptr) {
            // 终止条件: 3种情况
            if (p->val < root->val && q->val > root->val 
                || p->val > root->val && q->val < root->val) 
            {
                    result = root; break;
            }
            if (p->val == root->val) {result = root; break;}
            if (q->val == root->val) {result = root; break;}

            // 循环不变量
            if (p->val < root->val && q->val < root->val) {root = root->left;}
            if (p->val > root->val && q->val > root->val) {root = root->right;}
            
        }
        return result;
    }
};

// Solution 3
// 迭代法 简化版本

// 题目中保证了p q都不为nullptr
// BST与普通二叉树区别, 这里没有重复元素,且元素都是有序的.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {return root;}
        TreeNode* result = nullptr;
        while (root != nullptr) {
            // 循环不变量
            if (p->val < root->val && q->val < root->val) {root = root->left;}
            else if (p->val > root->val && q->val > root->val) {root = root->right;}
            // 终止条件: 3种情况
            else {
                result = root;
                break;
            }
        }
        return result;
    }
};
