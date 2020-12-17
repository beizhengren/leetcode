/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// 注意：只管将末尾置成nullptr即可。输出样例中的#，leetcode系统会根据nullptr自己输出。
// Solution 1
// 层序遍历
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {return nullptr;}
        queue<Node*> que;
        que.push(root);
        
        
        while (!que.empty()) {
            int size = que.size();
            // 对于每一层定义一个指针，负责把所有节点的next串联起来
            Node* curLevelNode = nullptr;
            for (int i = 0; i < size; ++i) {
                //常规层序遍历
                Node* node = que.front();
                que.pop();
                if(node->left != nullptr) {que.push(node->left);}
                if(node->right != nullptr) {que.push(node->right);}

                // 串联next
                if (i == 0) {
                    // 赋初值，为每一层的第一个节点
                    curLevelNode = node;
                } else {
                    // 指向下一个节点
                    curLevelNode->next = node;
                    //更新curLevelNode
                    curLevelNode = curLevelNode->next;
                }
            }
            // 到了当前层最后一个节点，要指向nullptr
            curLevelNode->next = nullptr;
        }
        return root;
    }
};
// Solution 2
// DFS
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {return nullptr;}
        dfs(root, 0);  
        return vecNext[0];
    }
private:
    vector<Node*> vecNext;

    void dfs (Node* node, int level) {
        if (node == nullptr) {return;}
        if (vecNext.size() == level) {
            vecNext.push_back(node);
        } else {
            vecNext[level]->next = node;
            vecNext[level] = vecNext[level]->next;
            // 每次最后都将next赋值为nullptr， 保证当前层最右侧的next为nullptr
            vecNext[level]->next = nullptr;
        }
        // 递归终止条件有对nullptr的判断，因此这里可以不判断节点指针是否为nullptr
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
};

// Solution 3
// DFS

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {return nullptr;}
        dfs(root);  
        return root;
    }
private:
    void dfs (Node* node) {
        if (node == nullptr) {return;}
        // 更新左孩子的next
        if (node->left) {
            node->left->next = node->right;
        }
        // 更新右孩子的next
        if (node->right) {
            if (node->next) {
                node->right->next = node->next->left;
            } else {
                node->right->next = nullptr;
            }
        }
        //递归以左、右孩子为根
        dfs (node->left);
        dfs (node->right);
    }
};
