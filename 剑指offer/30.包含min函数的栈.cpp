class Solution {
public:
    void push(int value) {
        stk.push(value);
        //一定要判断stkAid.size == 0，因为后面有top操作
        if(stkAid.size() == 0 ||value < stkAid.top()){
            stkAid.push(value);
        }else{
            stkAid.push(stkAid.top());
        }
    }
    void pop() {
        //一定要判断size == 0，因为后面有top操作
        if(stk.empty()) throw "stack is empty";
        else{
            stk.pop();
            stkAid.pop();    
        }
    }
    int top() {
        //一定要判断size == 0，因为后面有top操作
        if(stk.empty()) throw "stack is empty";
        else return stk.top();
    }
    int min() {
        //一定要判断stkAid.size == 0，因为后面有top操作
        if(stkAid.empty()) throw "stack is empty";
        else return stkAid.top();
    }

private:
    stack<int> stk;//数据栈
    stack<int> stkAid;//辅助栈
};
