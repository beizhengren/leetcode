class Solution {
public:
    int lastRemaining(int n, int m) {
        return lastRemaining4(n, m);
    }
    //O(n^2), 超时。因为erase。
    //注意：
    //如果直接声明一个vec，那么就emplace_back()
    //如果声明的是vec(n,0),那么就是vec[i] = ...
    int lastRemaining1(int n, int m){
        if(n < 1 || m < 1) return -1;
        vector<int> vec;
        for(int i = 0; i < n; ++i)
        {
            vec.emplace_back(i);
        }

        int idx = 0;
        for(int totalNum = n; totalNum > 1; --totalNum)
        {
            idx = (idx + m - 1) % totalNum;
            vec.erase( vec.begin() + idx);//vec的迭代器支持+数字
        }
        return vec[0];
    }

    // ring list O(nm)
    int lastRemaining2(int n, int m){
        list<int> l;//list 不支持subscript access
        for(int i = 0; i < n; ++i){
            l.push_back(i);
        }

        auto it = l.begin(); //iterator不支持 + number
        while(l.size() > 1){
            for(int i = 0; i < m - 1; ++i){
                ++it;
                //ring list
                if(it == l.end()) it = l.begin();
            }
            auto itNext = it;
            ++itNext;
            if(itNext == l.end()) itNext = l.begin();
            l.erase(it);
            it = itNext;
        }
        return *it;
    }

    //  recurcive
    int lastRemaining3(int n, int m)
    {
        if (n == 1) {
            return 0;
        }
        int x = lastRemaining3(n - 1, m);
        return (x + m) % n;
    }

    //iterate
    int lastRemaining4(int n, int m){
        int res = 0;
        for(int i = 1; i <= n; ++i){
            res = (res + m) % i;
        }
        return res;
    }

};
