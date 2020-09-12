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
    // https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/mian-shi-ti-26-shu-de-zi-jie-gou-xian-xu-bian-li-p/
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == nullptr || pRoot2 == nullptr)//树要是有空的，根据题意返回false
            return false;
        //以下三种满足一种就是true
        return  helper(pRoot1, pRoot2)//1. 从根节点开始， 是否包含pRoot2
                || HasSubtree(pRoot1->left, pRoot2)//2. 从左叶子点开始， 是否包含pRoot2
                || HasSubtree(pRoot1->right, pRoot2);//3. 从右叶子节点开始， 是否包含pRoot2
    }
    
    //判断以root2为根的树是否为pRoot1的子树
    bool helper(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot2 == nullptr) return true;//如果pRoot2遍历完，那么返回true
        if(pRoot1 == nullptr || pRoot1->val != pRoot2->val)return false;
        return helper(pRoot1->left, pRoot2->left)
            && helper(pRoot1->right, pRoot2->right);
    }
};
