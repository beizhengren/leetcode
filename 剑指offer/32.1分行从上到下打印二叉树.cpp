//参考https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/solution/c-ceng-xu-bian-li-dfsbfs-tao-mo-ban-jiu-wan-shi-li/
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
            vector<vector<int> > res;
            queue<TreeNode*> q;
            if(pRoot == nullptr) return res;//根节点为空直接返回
            q.push(pRoot);
            while(q.size()){
                vector<int> resOne;
                int size = q.size();//记录每一层的节点个数
                for(int i = 0; i < size; ++i){
                    auto root = q.front();q.pop();
                    resOne.push_back(root->val);
                    if(root->left != nullptr)
                        q.push(root->left);
                    if(root->right != nullptr)
                        q.push(root->right);
                }
                res.push_back(resOne);
            }
            return res;
        }
};
