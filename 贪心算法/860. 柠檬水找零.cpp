// Solution 1
// 贪心:
// 局部最优：遇到20元优先找10元
// 由局部最优可以得到全局最优，并且举不出反例
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

// Solution 2
// 优化：没有必要记录20元的数量，因为20不用于找零钱
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //[0] 5元, [1] 10元
        vector<int> moneyVec (2, 0);
        for (int i = 0; i < bills.size(); ++i) {
            if(moneyVec[0] < 0 || moneyVec[1] < 0) {
                break;
            }

            if (bills[i] == 5) {
                moneyVec[0]++;
            } else if (bills[i] == 10) {
                moneyVec[1]++;
                moneyVec[0]--;
            } else if (bills[i] == 20) {
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
        if(moneyVec[0] <0 || moneyVec[1] < 0) {
            return false;
        } else {
            return true;
        }
    }
};
// Solution 3
// 用两个变量就可以记录
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int i = 0; i < bills.size(); ++i) {
            if(five < 0 || ten < 0) {
                break;
            }

            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                ten++;
                five--;
            } else if (bills[i] == 20) {
                if (ten!=0){
                    ten--;
                    five--;
                }else {
                    five -= 3;
                }
                
            }
        }
        // 跳出有两种可能，一种没有访问到最后一个元素就break， 另一种是遍历到最后
        // 而在遍历到最后一次跳出的时候很有可能是找不开（不满足条件），所以一定要判断
        if(five < 0 || ten < 0) {
            return false;
        } else {
            return true;
        }
    }
};
