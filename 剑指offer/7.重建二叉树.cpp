/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return helper(pre, 0, pre.size(), vin, 0, vin.size());
    }
private:
    //区间都是左闭右开，和find函数相对应。
    TreeNode* helper(const vector<int>& preorder, int begPre, int endPre,
              const vector<int>& inorder, int begIn, int endIn){
        if(begPre >= endPre || begIn >= endIn){
            return nullptr;
        }
        //创建根节点
        TreeNode* root = new TreeNode(preorder[begPre]);
        //在中序序列中找到根节点值所在的位置
        auto midPos = find(inorder.begin()+begIn, inorder.begin()+endIn, root->val);
        //计算左右子树的节点个数->索引的区间
        auto dis = midPos - inorder.begin() - begIn;//中间点到当前中序序列的头的距离,因为会分成两个子序列，也就是头会变，一定要减去begIn
        root->left = helper(preorder, begPre + 1, begPre + 1 + dis,
                            inorder,  begIn, begIn + dis);
        root->right = helper(preorder, begPre+1+dis, endPre,
                            inorder, begIn+1+dis, endIn);
        return root;
    }
};
