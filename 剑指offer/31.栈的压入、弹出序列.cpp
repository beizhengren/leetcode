class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() && popV.empty()) return false;
        int i = 0, j = 0;
        for(; i < popV.size(); ++i){//陆续从popV中取元素
            if(stk.empty() || popV[i] != stk.top()){
                if(stk.empty()){//当前状态：栈中没有（输入序列的）元素。单独考虑
                    stk.push(pushV[j]);
                    if(stk.top() == popV[i]){//第一个元素想等，进入下次循环
                        stk.pop();continue;
                    }
                }

                while(popV[i] != stk.top() && j < pushV.size()){
                    stk.push(pushV[j]);
                    ++j;
                }
                //跳出循环有两种情况：值相等，或者j不满足条件（可能相等，可能不等）
                if(popV[i]!=stk.top()) return false;//值不等，直接返回false
            }
            stk.pop();//只要出来都是值相等（意味着有值，不为空；stk为空的情况在上面continue）
        }
        return true;
    }
private:
    stack<int> stk;//栈：用来保存输入序列
};
