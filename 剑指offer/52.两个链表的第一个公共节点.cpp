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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        auto cur1 = pHead1;
        auto cur2 = pHead2;
        while(cur1 != cur2){
            cur1 = cur1 ? cur1->next : pHead2;
            cur2 = cur2 ? cur2->next : pHead1;
        }
        return cur1;
    }
};
