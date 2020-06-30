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
///两个链表相加
//2->4->3  + 5->6->4 = 7->0->8
//output: 807
//链表头是低位,链表尾部是高位
//一个链表可能比另外一个链表长很多
///soultion 1
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        auto res1 = res;
        int add = 0;
        while(l1 && l2){
            int val = l1->val + l2->val + add;
            add = val / 10;
            int ge = val % 10;
            res->next = new ListNode(ge);
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == nullptr && l2==nullptr){
            
        }
        while(l1 != nullptr){//l1 不为空就一直向下走
            int val = l1->val + add;
            add = val / 10;
            int ge = val % 10;
            res->next = new ListNode(ge);
            res = res->next;
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            int val = l2->val + add;
            add = val / 10;
            int ge = val % 10;
            res->next = new ListNode(ge);
            res = res->next;
            l2 = l2->next;
        }
        
        if(add>0){
                res->next = new ListNode(add);
                res = res->next;
        }
        return res1->next;
    }
};
///solution 2
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;//上次求和-10
        while (l1 || l2 || extra) {
            //因为l1 和 l2 不一定同时存在,因此把 extra + l1->val + l2->val
            //拆成2步.即分别判断l1和l2是否存在
            if (l1) extra += l1->val, l1 = l1->next;//如果l1存在,相加,向下走
            if (l2) extra += l2->val, l2 = l2->next;//如果l2存在,相加,向下走
            //总要判断下一个节点的状态,并赋值,需要pre
            p->next = new ListNode(extra % 10);//即使l1 和 l2都不存在,也创建一个节点,值为extra
            extra /= 10;//进位值.如果extra<10,那么extra=0
            p = p->next;//p向下走
        }
        // p->next = nullptr;
        return preHead.next;
    }
};
