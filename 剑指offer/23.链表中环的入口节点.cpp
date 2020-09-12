/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr) return pHead;
        //0. tell if there is a circle
        auto pSlow = pHead;
        auto pFast = pHead;
        bool isExist = false;
        while(pFast != nullptr && pSlow != nullptr&&pSlow->next&& pFast->next){
                    pFast = pFast->next->next;
                    pSlow = pSlow->next;    
                 if(pFast == pSlow){isExist = true; break;}
        }
        //1. calculate the circle length
        if(isExist == false){
            return nullptr;
        }
        //2. seek the entry of the circle
        auto cur1 = pHead;
        while(cur1 != pSlow){
                cur1 = cur1->next;
                pSlow = pSlow->next;
            
        }
        return cur1;
    }
};
