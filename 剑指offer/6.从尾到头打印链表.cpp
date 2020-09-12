/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    //从尾到头，用栈来实现。
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head == nullptr) return res;
        stack<ListNode*> stk;
        while(head != nullptr){
            stk.push(head);
            head = head->next;
        }
        while(!stk.empty()){
            auto& node = stk.top();
            res.emplace_back(node->val);
            delete node;
            stk.pop();
        }
        return res;
    }
};
