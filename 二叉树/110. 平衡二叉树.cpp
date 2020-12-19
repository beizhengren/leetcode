// 二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数。 从上到下去查 所以需要前序遍历（中左右）
// 二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数。 从下到上去查，所以只能后序遍历（左右中）
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
private:
    //求以node为节点的高度（自底向上，也就是叶子节点到当前节点）
    int getHeight (TreeNode* node) {
        //根
        if (node == nullptr) { return 0;}
        //左子树高度
        int heightL = getHeight(node->left); 
        //右子树高度
        int heightR = getHeight(node->right);
        //用-1标志不是平衡的。左右子树任一不平衡，当前树都不平衡
        if (heightL == -1 || heightR == -1) {return -1;}
        //左右子树平衡的时候，要判断是否高度差大于1
        if (abs(heightL - heightR) >= 2) {return -1;}
        //平衡，就返回当前树的高度
        return 1 + max(heightL, heightR);
    }
};
