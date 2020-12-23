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
    // BST 中序遍历: 从小到大, 相同的数字是排在一起的
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
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) {return result;}
        TreeNode* pre = nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            if (stk.top()) {
                TreeNode* cur = stk.top();
                stk.pop();
                //inorder: l m r
                if (cur->right) {stk.push(cur->right);}
                stk.push(cur);
                stk.push(nullptr);
                if (cur->left) {stk.push(cur->left);}
            } else {
                stk.pop();
                TreeNode* cur = stk.top();
                stk.pop();
                
                // 更新count
                if (pre == nullptr) {
                    count = 1;
                } else if (pre->val == cur->val) {
                    ++count;
                } else if (pre->val != cur->val) {
                    count = 1;
                }
                // 更新pre
                pre = cur;
                // 更新 maxCount 和 result
                if (count == maxCount) {
                    result.push_back(cur->val);
                }
                if (count > maxCount) {
                    maxCount = count;
                    result.clear();
                    result.push_back(cur->val);
                }
            }
        }
        return result;
    }
private:
    vector<int> result;
    int count = 0;
    int maxCount = 0;
};

// Solution 3
// 普通二叉树解法 
// DFS 前中后序都可以
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) {return {};}
        traversal(root);
        vec.assign(umap.begin(), umap.end());
        // 按照频率由大到小排序
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int>b ){ return a.second > b.second;});
        // 存入第一个(最大的)
        result.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i].second == vec[i-1].second) {
                result.push_back(vec[i].first);
                
            } else {
                break;
            }
        }
        return result;
    }

private:
    
    void traversal(TreeNode* cur) {
        if (cur == nullptr) {return;}
        umap[cur->val]++; //统计频率
        traversal(cur->left);
        traversal(cur->right);
    }
    // element, times
    unordered_map<int, int> umap;
    vector<pair<int, int> > vec;
    vector<int>result;
};
