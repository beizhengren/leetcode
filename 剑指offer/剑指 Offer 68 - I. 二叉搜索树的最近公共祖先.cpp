//  https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-36/

// 解法1：循环
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //root 已经判断是否为nullptr，如果为nullptr，直接跳到末尾返回。
        while(root){
            if(root->val < p->val && root->val < q->val){ root = root->right;}
            else if(root->val > p->val && root->val > q->val){ root = root->left;}
            else{break;}
        }
        //假设都可以找到，那么root就不为nullptr。
        return root;
    }
};

//解法2：递归

class Solution {
private:
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur->val > p->val && cur->val > q->val) {
            return traversal(cur->left, p, q);
        } else if (cur->val < p->val && cur->val < q->val) {
            return traversal(cur->right, p, q);
        } else return cur;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return traversal(root, p, q);
    }
};
