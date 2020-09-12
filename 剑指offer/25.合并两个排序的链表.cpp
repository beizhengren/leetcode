/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {   auto l1 = pHead1;
        auto l2 = pHead2;
        if(l1 == nullptr && l2 ==nullptr) return nullptr;
        if(l1 != nullptr && l2 ==nullptr) return l1;
        if(l2 != nullptr && l1 ==nullptr) return l2;

        ListNode* head = nullptr;
        //recursive
        if(l1->val < l2->val) {
            head = l1;
            head->next = Merge(l1->next, l2);
        }
        else{ 
            head = l2;
            head->next = Merge(l1, l2->next);
        }
        return head;
    }
};



