class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1,
                        inorder, 0, inorder.size()-1);

    }

    TreeNode* buildTree(vector<int>& preorder, int preorderBeg, int preorderEnd,
                        vector<int>& inorder, int inorderBeg, int inorderEnd) 
    {      
             // 空节点
            if (preorderBeg > preorderEnd || inorderBeg > inorderEnd) {return nullptr;}
            // root
            TreeNode* root = new TreeNode(preorder[preorderBeg]);
            // 递归终止条件
            if (preorderBeg == preorderEnd) {return root;}

            // 在inorder中找rootIdx 
            int rootIdx = 0;
            for (int i = inorderBeg; i <= inorderEnd; ++i) {
                if (inorder[i] == root->val) {
                    rootIdx = i;
                    break;
                }
            }
            // [inorderBeg, rootIdx - 1] [rootIdx + 1, inorderEnd]
            // 左右子树的大小
            int leftSize = (rootIdx - 1) - inorderBeg + 1;
            int rightSize = inorderEnd - (rootIdx + 1) + 1;
            // 确定前序的左右子树的区间
            int leftPreorderBeg = preorderBeg + 1;
            int leftPreorderEnd = leftPreorderBeg + leftSize - 1;
            int rightPreorderBeg = leftPreorderEnd + 1;
            int rightPreorderEnd = preorderEnd;
            // 递归求得左右子节点
            root->left = buildTree(preorder, leftPreorderBeg, leftPreorderEnd,
                                inorder, inorderBeg, rootIdx - 1);
            root->right = buildTree(preorder, rightPreorderBeg, rightPreorderEnd,
                                inorder, rootIdx + 1, inorderEnd);
            return root;
    }

};
