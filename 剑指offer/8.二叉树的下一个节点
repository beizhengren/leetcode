/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr) return nullptr;
        //中序遍历：左->中->右。因此左子树的节点的最远也就是其祖先节点，
        //不可能跨越到祖先节点的右子树
        TreeLinkNode* pNext = nullptr;
        if(pNode->right != nullptr){//节点有右子树
            TreeLinkNode* pRight = pNode->right;
            while(pRight->left != nullptr)
                pRight = pRight->left;

            pNext = pRight;
        }
        else if(pNode->next != nullptr){//节点无右子树
            TreeLinkNode* pCurrent = pNode;
            TreeLinkNode* pParent = pNode->next;
            while(pParent != nullptr && pCurrent == pParent->right){
                pCurrent = pParent;
                pParent = pParent->next;
            }
            //此时，pParent要么为空，要么就是->left = pCurrent
            pNext = pParent;
        }

            return pNext;
        }
};
