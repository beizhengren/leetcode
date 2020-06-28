/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
///solution 1
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        assert(m <= n);
        ListNode* cur = head;
        ListNode* pre = nullptr;
        
        for(int i = 0; i < m; ++i){
            pre = cur;
            cur= cur->next;
        }
        ListNode* subTail = pre;
        for(int i = m; i < n; ++i){
            ListNode* next = cur->next;
            
            pre = cur;
            cur = next;
        }
        ListNode* subHead = pre;
        
        ListNode* subHead0 = subTail->next;
        
        subHead0->next = subHead;
        subTail->next = cur;
        return head;
    }
};
