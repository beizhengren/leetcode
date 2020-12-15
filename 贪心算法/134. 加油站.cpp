// Solution 1
// 暴力解法
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); ++i) {
            int rest = gas[i] - cost[i];
            // 下一个加油站下标
            int index = (i + 1) % gas.size();
            //从当前i开始出发，看看能不能行使一圈
            //必须每次判断rest > 0
            while (rest > 0) {
                rest = rest + gas[index] - cost[index];
                index = (1 + index) % gas.size();
                if(index == i) {break;}
            }
            // 两种原因可能跳出循环
            // 所以要判断rest是否大于等于0 且index==i
            if (rest>=0 && index==i) {return i;}

        }
        return -1;
    }
};
