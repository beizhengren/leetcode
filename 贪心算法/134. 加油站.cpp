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

// Solution 2
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 用于判断最终是否能够跑一圈， 因为总和>0必然能够跑一圈。
        // 总和大于零，说明油箱里剩下的油总够所有路程cost消耗的
        int totalSum = 0; 
        int curSum = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int rest = gas[i] - cost[i];
            curSum += rest;
            totalSum += rest;
            // 1.curSum < 0，说明不能从i出发。那么就要尝试从i+1出发，curSum就要从新计算。
            // 2.从i+1出发，如果curSum一直>=0，start就不做更新。
            // （说明从i+1出发到最后是可以完成的，至于能否完成整圈，需要根据最后totalSum判断）
            // 3.如果又出现了curSum < 0的情况就像1.一样更新start。
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }

        if (totalSum >= 0) {return start;}
        else {return -1;}
    }
};
