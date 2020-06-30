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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(0);
        ListNode* evenHead = new ListNode(0);
        auto oh = oddHead;
        auto eh = evenHead;
        while(head && head->next && head->next->next){
            oddHead->next = head;
            evenHead->next = head->next;
            head = head->next->next;
            
            oddHead = oddHead->next;
            evenHead = evenHead->next;
        }
        if(!head){
           
        }else if(!head->next){
            oddHead->next = head;
            oddHead= oddHead->next;

        }else if(!head->next->next){
            oddHead->next = head;
            evenHead->next = head->next;     
            oddHead = oddHead->next;
            evenHead = evenHead->next;
        }
        oddHead->next = eh->next;
        evenHead->next = nullptr;   
        auto res = oh->next;
        delete oh, eh;
        return res;
    }
};

///solution 2
class Solution {
public:
       ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode *odd=head, *evenhead=head->next, *even = evenhead;
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};
