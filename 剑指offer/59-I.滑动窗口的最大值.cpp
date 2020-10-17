//https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/cjie-jian-dian-zan-zui-gao-de-fang-fa-zhu-yao-zuo-/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> tmp;
        if(size == 0)return res;
        for(int i = 0; i < num.size(); ++i)
		{
            //保证队首存储的是当前滑窗的最大值对应的index
            //注意：比较的是元素值，如果数组中当前元素大于队列尾的index对应的数组元素的值
            while(!tmp.empty() && num[i] > num[tmp.back()])
            {
                tmp.pop_back();
            }
            //如果队首的元素的index小于当前滑窗的第一个元素的index，就pop front
            //注意：size是 unsigned，如果“tmp.front() < i - size + 1”，会报错！！！
            if(!tmp.empty() && tmp.front() + size < i + 1)
                tmp.pop_front();
            //队列尾部存入当前元素对应的index
            tmp.push_back(i);
            //如果当前元素的index大于size-1，说明已经达到了滑窗的大小，
            //注意：存入res的值是tmp的index对应的num中的元素值
            if(i >= size-1) res.push_back(num[tmp.front()]);
        }
        return res;
    }   
};
