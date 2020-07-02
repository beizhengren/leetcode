/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
///solution 1
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode(0);
        ListNode* cur = head;
        pre->next = cur;
        auto del = pre;
        while(cur){
            ListNode* next = cur->next;
            if(cur->val == val){
                auto delN = cur;
                cur = next;
                pre->next = cur;
                delete delN;
            }else{
                pre = cur;
                cur = next;          
            }
        }
        auto res = del->next;
        delete del;
        return res;
            
    }
};

///solution 2
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto pre = new ListNode(0);
        auto del = pre;
        pre->next = head;
        while(pre->next){
            if(pre->next->val == val){
                auto tmp = pre->next;
                pre->next = pre->next->next;
                delete tmp;
            }else{
                pre = pre->next;
            }
        }
        auto res = del->next;
        delete del;
        return res;
    }
};
