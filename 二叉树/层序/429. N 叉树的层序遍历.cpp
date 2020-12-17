/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 跟二叉树的区别在于，孩子节点用vector来保存，遍历的时候需要遍历整个vector
// Solution 1
// 层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) {return result;}
        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            vector<int> layerResult;
            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                que.pop();
                layerResult.emplace_back(node->val);

                for (int j = 0; j < node->children.size(); ++j) {
                    if (node->children[j] != nullptr) {
                        que.push(node->children[j]);
                    }
                }
            }
            result.emplace_back(layerResult);
        }
        return result;
    }
};

// Solution2
// DFS
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {return result;}
        dfs(root, 0);
        return result;
    }

private:
    void dfs (Node* node, int level) {
        if (node == nullptr) {return;}
        // level + 1 = result.size(); level 是从0开始，相当于index
        // level是0，对应result的size应该是1
        if (level == result.size()) {
            result.emplace_back(vector<int>{});
        }
        result[level].push_back(node->val);
        for (auto& child : node->children) {
            if (child != nullptr){
                dfs(child, level+1);
            }
        }
    }

    vector<vector<int>> result;
};
