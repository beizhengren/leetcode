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

//solution 1
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        //需要从链表的第一个开始计算,并且记住前面的节点,故要用pre表示
        while(pre->next && pre->next->val < x)
                pre = pre->next;//满足<x继续往后走
        cur = pre;//cur list start with pre that a sublist of head

        while(cur->next){
            if(cur->next->val >= x) cur = cur -> next;//如果满足>=x就继续往后走,直到碰到不满足的
            else {
                ListNode* tmp = cur -> next;
                cur -> next = tmp -> next; //cur -> next = cur -> next -> next, jump over the node in middle
                tmp -> next = pre -> next;
                pre -> next = tmp;
                pre = pre ->next;


            }
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};

///solution 2
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        ListNode* h1 = head1;
        ListNode* h2 = head2;
        
        while(head){
            if(head->val < x){
                // next intialzed value is nullptr, so assign value. point to head
                head1->next = head;
                head1 = head1->next;
            }else{
                head2->next = head;
                head2 = head2->next;
            }
            head = head->next;
        }
        
        head2->next = nullptr;
        head1->next = h2->next;
        auto res = h1->next;
        delete h1;
        delete h2;
        return res;
        
    }
    
};
