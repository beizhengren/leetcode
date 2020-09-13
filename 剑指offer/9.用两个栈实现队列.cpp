class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
            if(!stack2.empty()){//stack2 栈顶本身存的就是最先进入stack1的
                int res = stack2.top();//如果不为空，直接取出。
                stack2.pop();
                return res;
            }else{//stack2为空
                if(!stack1.empty()){
                    while(!stack1.empty()){//将stack1所有元素导入stack2
                        auto tmp = stack1.top();stack1.pop();
                        stack2.push(tmp);
                    }
                    int res = stack2.top();//取出返回值
                    stack2.pop();//
                    return res;
                }
                else{//stack1 stack2 都为空，队列为空
                    throw "queue is empty";
                }
            }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
