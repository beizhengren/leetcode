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
//Note:
//Given n will always be valid.

///solution 1
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        
        auto dummyHead = new ListNode(0);
        dummyHead->next = head;
        auto ptr1 = dummyHead;
        auto ptr2 = dummyHead;
        
        for(int i = 0; i < n; ++i){
            ptr2 = ptr2->next;
        }
        
        while(ptr2->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        auto del = ptr1->next;
        ptr1->next = ptr1->next->next;
        delete del;
        auto res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};


///solution 2
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(n>=0);
        auto dummyHead = new ListNode(0);
        dummyHead->next = head;
        auto p = dummyHead;
        auto q = dummyHead;
        //保证p 和 q的间距是 n.就要让q走n+1次
        for(int i = 0; i < n+1; i++){
            assert(q);
            q = q->next;
        }
        
        while(q){
            p = p->next;
            q = q->next;
        }
        
        auto delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        
        auto retNode = dummyHead->next;
        delete dummyHead;
        
        return retNode;
    }
};
