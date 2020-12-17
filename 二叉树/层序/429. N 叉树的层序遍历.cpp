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
