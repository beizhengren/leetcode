/*
BST是由大小顺序的，
1. 在搜索的时候可以比较元素大小直接找到路径，
而不用递归。
2. BST按照中序遍历就是一个从小到大的数组。注意二叉搜索树中不能有重复元素。
3. 空节点是BST
*/

/*
本题陷阱1：「不能单纯的比较左节点小于中间节点，右节点大于中间节点就完事了」。
if (root->val > root->left->val && root->val < root->right->val) {
    return true;
} else {
    return false;
}
我们要比较的是 左子树所有节点小于中间节点，右子树所有节点大于中间节点。
所以以上代码的判断逻辑是“错误”的。
*/

/*
本题陷阱2：
样例中最小节点 可能是int的最小值，如果这样使用最小的int来比较也是不行的。
可以用long long max = LONG_MIN
但是不好。应该用一个TreeNode* pre 来保存之前的节点。
*/

// Solution 1
// 用O(N)的额外空间
class Solution {
public:
    //BST 按照中序遍历必然是从小到大的
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {return true;}
        traversal(root);
        for (int i = 0; i < vec.size(); ++i) {
            //如果有一个不满足条件就返回false；
            if (i > 0 && vec[i] <= vec[i-1]) {
                return false;
            }
        }
        return true;
    }
private:
    void traversal(TreeNode* node) {
        if (node == nullptr) {return;}
        traversal(node->left);
        vec.push_back(node->val);
        traversal(node->right);
    }
    vector<int> vec;
};

// Solution 2
// 递归 S(N) = O(1)
class Solution {
public:
    //BST 按照中序遍历必然是从小到大的
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {return true;}
        // 左
        bool bLeft = isValidBST(root->left);
        // 中
        if (pre != nullptr && pre->val >= root->val) {
            return false;
        }
        pre = root; // 用pre记录前一个节点，每次都更新
        
        // 右
        bool bRight = isValidBST(root->right);
        return bLeft && bRight;
    }
private:
    TreeNode* pre = nullptr;
};
