/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical(pRoot, pRoot);
    }
    
    bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2){
        //考虑nullptr, 都为nullptr，返回ture
        if(pRoot1 == nullptr && pRoot2 == nullptr) return true;
        
        //有一个为nullptr，另外一个不为nullptr，说明节点指针存在状态不同，返回 false
        if(pRoot1 == nullptr || pRoot2 == nullptr) return false;
        
        //节点的值不同，返回false
        if(pRoot1->val != pRoot2->val) return false;
        
        return isSymmetrical(pRoot1->left, pRoot2->right)
            && isSymmetrical(pRoot1->right, pRoot2->left);
            
    }

};
