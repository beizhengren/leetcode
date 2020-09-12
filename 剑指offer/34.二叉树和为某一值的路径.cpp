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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        res.clear();
        //if(root == nullptr) return res;
        findPath(root, expectNumber);
        return res;
    }
private:
    //寻找root为根，和为eval的路径，存入到res中。
    void findPath(TreeNode* root,int eval){
        //1. 终止条件：当前节点为叶节点，并且值=eval，保存返回。
        //1.1 不满足，返回。
        if(root == nullptr){
            return;
        }
        //1.2 满足，当前节点为叶节点，并且值=eval，保存返回。
        if(root->left == nullptr && root->right == 0 && root->val == eval){
            resOne.push_back(eval);
            res.push_back(resOne);
            resOne.pop_back();
            return;
        } 
        //2递归过程。存入当前值，遍历左右子树
        resOne.push_back(root->val);
        findPath(root->left, eval - root->val);
        findPath(root->right,eval - root->val);
        resOne.pop_back();//回溯
    }
    vector<vector<int> > res;
    vector<int> resOne;
};
