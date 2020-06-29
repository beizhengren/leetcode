
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
        return dummy -> next;
    }
};

