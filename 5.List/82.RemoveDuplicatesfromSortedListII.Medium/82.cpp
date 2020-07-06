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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto pre = new ListNode(0);
        auto delN = pre;
        pre->next = head;
        if(head == nullptr) return head;
        while(pre->next->next){
            auto tmp = pre->next;
            
            while(pre->next->val == pre->next->next->val){
                delete pre->next;
                pre = pre->next->next;
            }
            
        }
        auto res = delN->next;
        delete delN;
        return res;
    }
};
