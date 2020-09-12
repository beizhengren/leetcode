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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* tail = nullptr;
        helper(pRootOfTree, tail);
        while(tail!=nullptr && tail->left!=nullptr) tail=tail->left;
        return tail;
    }

private:
    //从顶层考虑递归，即：左子树（递归）-> 根 -> 右子树（递归）
    //root是未排序的链表头， tail是排好序的链表尾
    //因为tail变量本身需要更新，这里必须是指针的引用
    void helper(TreeNode* root, TreeNode*& tail){
        if(root == nullptr) return;
        auto cur = root;
        
        if(cur->left!=nullptr) helper(cur->left, tail);//1.递归左子树
        //2.根，交换。left指向排好序的链表尾
        cur->left = tail;
        if(tail!=nullptr) tail->right = cur; //因为tail初始为空，必须判断tail是否为空
        //3.右子树
        tail = cur;//更新链表尾巴
        if(cur->right!=nullptr) helper(cur->right, tail);
        
    }
    
};
