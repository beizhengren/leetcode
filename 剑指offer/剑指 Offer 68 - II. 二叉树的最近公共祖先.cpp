// https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/zui-jin-gong-gong-zu-xian-wen-ti-by-walkerr/
// 递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //当前节点cur = root，找到p 或者q 或者访问的是空节点
        if(root == p || root == q || root == nullptr) {return root;}
        else//当前节点既不是p也不是q，且不是空，向下访问（查找）
        {
            TreeNode* res = nullptr;
            auto pLNode = lowestCommonAncestor(root->left, p, q);
            auto pRNode = lowestCommonAncestor(root->right, p, q);
            //当前节点的左右子树分别找到p q， 说明p q 位于root异侧，返回root。
            if(pLNode != nullptr && pRNode != nullptr){res = root;}
            //当前节点的子树中没有找到p q，返回nullptr。
            else if(pLNode == nullptr && pRNode == nullptr){res = nullptr;}
            //当前节点只找到一个节点p或者q，返回p或者q。
            else{res = pLNode ? pLNode : pRNode;}
            return res;
        }
    }
};
