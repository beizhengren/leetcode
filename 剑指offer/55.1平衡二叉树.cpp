class Solution {
public:
    //后序遍历:左子树->右子树->根；一边遍历，一边记录左右子树深度，并作判断。
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int level = 0;
        return helper(pRoot, level);
    }
    
    //以root为根，初始深度为level，判断是否为平衡二叉树。
    bool helper(TreeNode* root, int& level){
        if(root == nullptr){//访问到空节点，设置深度=0，并返回true。
            level = 0;
            return true;
        }
        
        int lLevel = 0, rLevel = 0;//左右子树的初始深度都为0。
        //递归左子树，右子树看是否为平衡的
        if(helper(root->left, lLevel) && helper(root->right, rLevel)){
            //如果左右子树都是平衡的，计算左右子树的高度差。
            int diff = lLevel - rLevel;
            //如果左右子树的高度差满足平衡条件，那么就继续求以root为根的高度
            if(diff <= 1 && diff>= -1){
                //求以root为根的树的高度
                level = 1 + (lLevel > rLevel ? lLevel : rLevel);
                return true;
            }
        }
        return false;
    }
};
