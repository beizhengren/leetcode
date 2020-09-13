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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> >res;
        if(pRoot == nullptr) return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        int layer = 0;
        while(q.size()){
            int size = q.size();
            vector<int> resOne;//for current layer
            for(int i = 0; i < size; ++i){
                auto root = q.front(); q.pop();
                resOne.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);    
            }
            if(resOne.size()!=0){
                if(layer%2==0){//even:left->right
                    res.emplace_back(resOne);
                }
                else{//odd:right->left
                    //std::reverse(resOne.begin(), resOne.end());//反转
                    //res.emplace_back(resOne);
                    vector<int> tmp(resOne.rbegin(), resOne.rend());//反转
                    res.emplace_back(tmp);
                }            
            }
            ++layer;
        }
        return res;
    }
};
