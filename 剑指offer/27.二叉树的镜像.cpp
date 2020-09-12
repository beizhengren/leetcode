/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr) return;
        if(pRoot->left) Mirror(pRoot->left);
        if(pRoot->right) Mirror(pRoot->right);
        swap(pRoot->left, pRoot->right);
    }
};
