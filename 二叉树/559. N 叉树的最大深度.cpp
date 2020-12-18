// Solution 1
// 迭代: 层序
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {return 0;}
        int result = 0;
        queue<Node*> que;
        que.push(root);
    
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                que.pop();//务必在取出元素之后pop掉
                for (const auto& element : node->children) {
                    if (element != nullptr) {
                        que.push(element);
                    }
                }
            }
            ++result;
        }
        return result;
    }
};

// Solution 2
// 递归
class Solution {
public:
    int maxDepth(Node* root) {
        return getMaxDepth(root);
    }
private:
    int getMaxDepth(Node* node) {
        if (node == nullptr) {return 0;}
        int result = 0;
        for (int i = 0; i < node->children.size(); ++i) {
            result = max (result, getMaxDepth(node->children[i]));
        }
        return 1 + result;
    }
};

// 或者
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {return 0;}
        int result = 0;
        for (int i = 0; i < root->children.size(); ++i) {
            result = max (result, maxDepth(root->children[i]));
        }
        return 1 + result;
    }
};
