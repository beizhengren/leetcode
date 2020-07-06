/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//给定当前节点,删除当前节点.
//由于拿不到当前节点的前一个节点,所以只能将下一个节点的值赋给当前节点.
//然后删除下一个节点,并把当前节点指向下一个的下一个节点.

//solution 1
class Solution {
public:
    void deleteNode(ListNode* node) {
       if(node == nullptr){return;}
       if(node->next == nullptr){
           delete node;
           node = nullptr;
           return;
       } 
       //可以只保留这部分,因为题意明确节点都是有效的
       auto del = node->next;
       node->val = node->next->val;
       node->next = node->next->next;
       delete del;
    }
};
/*The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.
 */
//solution 2
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto next = node->next;
        *node = *next;
        delete next;
    }
};
