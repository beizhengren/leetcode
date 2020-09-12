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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
       res.clear();
       if(root == nullptr) return res;
       qNode.push(root);
       while(!qNode.empty()) {
            auto head = qNode.front();
            res.push_back(head->val);
                        qNode.pop();

           if(head->left)
                qNode.push(head->left);
            if(head->right)
                qNode.push(head->right);
       }
        return res;
    }
private:
    queue<TreeNode*> qNode;
    vector<int>res;
    
};
