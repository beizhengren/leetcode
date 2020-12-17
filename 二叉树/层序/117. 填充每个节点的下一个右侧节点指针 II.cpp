

// Solution 1
// BFS
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {return nullptr;}

        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            Node* curLevelNode = nullptr;
            for (int i = 0; i < size; ++i) {
               Node* node = que.front();
               que.pop();
               if (node->left) {que.push(node->left);} 
               if (node->right) {que.push(node->right);}

               if (i == 0) {
                   curLevelNode = node;
               } else {
                   curLevelNode->next = node;
                   curLevelNode = curLevelNode->next;
               }
            }
            curLevelNode->next = nullptr;
        }
        return root;
    }
};
