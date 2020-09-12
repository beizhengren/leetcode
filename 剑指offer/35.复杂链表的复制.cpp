/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr) return nullptr;
        //1.create new nodes and update next
        auto cur = pHead;
        while(cur != nullptr){
            auto tmp = new RandomListNode(cur->label);
            tmp->next = cur->next;
            
            cur->next = tmp;
            cur = tmp->next;
        }
        //2.update random
        cur = pHead;
        while(cur != nullptr&& cur->next!=nullptr){
             auto cpNode = cur->next;
             if(cur->random!=nullptr){
                 cpNode->random = cur->random->next;
             }
             cur = cpNode->next;
        }
        //3.decompose list
        cur = pHead;
        auto dummyHead = new RandomListNode(0);
        //dummyHead->next = cur->next;
        auto curCp = dummyHead;
        while(cur!=nullptr && cur->next!=nullptr){
            //需要将两个链表都串起来
            curCp->next = cur->next;
            curCp = curCp->next;
            
            cur->next = cur->next->next;
            cur = cur->next;
        }
        curCp->next=nullptr;
        auto res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};
