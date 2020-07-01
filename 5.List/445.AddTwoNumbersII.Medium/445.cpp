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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* pre = new ListNode(0);
        auto del = pre;
	//push elements of list to stack
        while(l1 || l2){
            if(l1){s1.push(l1->val), l1 = l1->next;}
            if(l2){s2.push(l2->val), l2 = l2->next;}   
        }
	//sum, and make a new list
        int sum = 0;
        while(s1.size() || s2.size() || sum){
            if(s1.size() >0) sum += s1.top(), s1.pop();
            if(s2.size() >0) sum += s2.top(), s2.pop();
            ListNode* tmp = new ListNode(sum%10);
            sum /=10;
            pre->next = tmp;
            pre = pre->next;
        }
        auto res = del->next;
        delete del;
        //reverse List
        ListNode* dummy = nullptr;
        while(res){
            auto tmp = res->next;
            res->next = dummy;
            dummy = res;
            res = tmp;
        }

        return dummy;
        
    }
};

///solution 2
//改进版,不需要单做一次反转链表
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while(l1 || l2){
            if(l1){s1.push(l1->val), l1 = l1->next;}
            if(l2){s2.push(l2->val), l2 = l2->next;}   
        }
        int sum = 0;
        ListNode* cur = nullptr;
        while(s1.size() || s2.size() || sum){
            if(s1.size() >0) sum += s1.top(), s1.pop();
            if(s2.size() >0) sum += s2.top(), s2.pop();
            ListNode* tmp = new ListNode(sum%10);
            sum /=10;
            tmp->next = cur;
            cur = tmp;//向节点头部移动,把当前新创建的节点地址赋值给cur
        }
        return cur;
    }
};
