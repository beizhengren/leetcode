class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        vector<int> moneyVec (3, 0);
        for (int i = 0; i < bills.size(); ++i) {
            if(moneyVec[0] < 0 || moneyVec[1] < 0 || moneyVec[2] < 0) {
                break;
            }

            if (bills[i] == 5) {
                moneyVec[0]++;
            } else if (bills[i] == 10) {
                moneyVec[1]++;
                moneyVec[0]--;
            } else if (bills[i] == 20) {
                moneyVec[2]++;
                if (moneyVec[1]!=0){
                    moneyVec[1]--;
                    moneyVec[0]--;
                }else {
                    moneyVec[0] -= 3;
                }
                
            }
        }
        // 跳出有两种可能，一种没有访问到最后一个元素就break， 另一种是遍历到最后
        // 而在遍历到最后一次跳出的时候很有可能是找不开（不满足条件），所以一定要判断
        if(moneyVec[0] <0 || moneyVec[1] < 0 || moneyVec[2] < 0) {
            return false;
        } else {
            return true;
        }
    }
};
