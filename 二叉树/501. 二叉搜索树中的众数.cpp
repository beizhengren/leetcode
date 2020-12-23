// Solution 1
// DFS 用pre 和 cur

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) {return result;}
        traversal(root);
        return result;
    }

private:
    // inorder: 从小到大, 相同的数字是排在一起的
    void traversal (TreeNode* cur) {
        // 0. 递归终止条件
        if (cur == nullptr) {return;}
        // 1. 左
        traversal(cur->left);
        // 2. 中
        // 2.1
        if (pre == nullptr) {
            count = 1; //第一个节点进来了, 它的前一个节点pre必然为nullptr
        }
        else if (cur->val == pre->val) {
            ++count; // 从第二个开始
        } else if (cur->val != pre->val) {
            count = 1; // 当前节点和pre的值不等,那么就重新计数
        }
        
        // 2.2更新节点
        // BST中更新节点一定是每次都无条件更新,和链表一样
        pre = cur;

        // 2.3 判断maxCount
        // 2.3.1 相等, 说明有重复的众数
        if (count == maxCount) {
            result.push_back(cur->val);
        }
        // 2.3.2 大于,清理之前保存的结果,更新maxCount,并将最新的众数保存
        if (count > maxCount) {
            result.clear();
            maxCount = count;
            result.push_back(cur->val);
        }

        // 3.右
        traversal(cur->right);
    }

    vector<int>result{};
    // 下面三个都可以传参数,保证不用额外空间.
    TreeNode* pre = nullptr;
    int maxCount = 0;
    // 统计当前节点的重复次数,必须全局变量或者传引用, 
    // 因为当前节点的count,其他节点也会用到
    int count = 0;
};

// Solution 2
// 迭代法

