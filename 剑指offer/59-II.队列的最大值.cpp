//https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/ru-he-jie-jue-o1-fu-za-du-de-api-she-ji-ti-by-z1m/
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(aid.empty()) return -1;
        else return aid.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!aid.empty() && aid.back() < value ){
            aid.pop_back();
        }
        aid.push_back(value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int res = q.front();
        if(q.front() < aid.front()) q.pop();
        else{
            q.pop();
            aid.pop_front();
        }
        return res;
    }
private:
    deque<int> aid;
    queue<int> q;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
