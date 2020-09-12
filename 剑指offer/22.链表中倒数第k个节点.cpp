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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr) return nullptr;
        auto pRes = pListHead;
        auto pCur = pListHead;
        for(int i = 0; i < k; ++i){
            if(pCur != nullptr)
                pCur = pCur->next;
            else{
                return nullptr;
            }
        }
        while(pCur != nullptr){
            pCur = pCur->next;
            pRes = pRes->next;
        }
        return pRes;
    }
};
