class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() <= 2) return;
        map<int, int> m;
        for(int i = 0; i < data.size(); ++i){
            m[data[i]]++;
        }
        
        int arr[2];
        int i = 0;//局部变量这么定义比较清楚
        for(auto it = m.begin(); it!=m.end(); ++it){
            if (it->second == 1){
                arr[i] = it->first;
                ++i;
            }
        }
        
        *num1 = arr[0];
        *num2 = arr[1];
    }
};
/*
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        unordered_map<int, int> mp;
        for (const int k : data) ++mp[k];
        vector<int> ret;
        for (const int k : data) {
            if (mp[k] == 1) {
                ret.push_back(k);
            } 
        }
        *num1 = ret[0];
        *num2 = ret[1];
    }
};
*/
