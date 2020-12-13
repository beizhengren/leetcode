class Solution {
public:
    // 其中的vector<string> 只有两个元素[起始机场，到达机场]
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 记录映射关系，以起始航班出发，到达航班按照字典序（并记录次数）
        for (int i = 0; i < tickets.size(); ++i) {
            targets[tickets[i][0]][tickets[i][1]]++;
        }
        // 起始机场
        result.push_back("JFK");
        backtracking(result, tickets.size());
        return result;
    }
private:
    // bool返回类型，因为我们只需要找到一个行程，就是在树形结构中唯一的一条通向叶子节点的路线
    // 参数里还需要ticketNum，表示有多少个航班（终止条件会用上）
    bool backtracking(vector<string>&result, int ticketNum) {
            // 机场的个数等于 机票的个数+1
            if (result.size() == ticketNum + 1) {
                return true;
            }

            for (auto& it : targets[result.back()]) {
                // 记录到达机场还能够飞的次数
                if (it.second > 0) {
                    // 将起飞机场保存
                    result.push_back(it.first);
                    // 相应的路线（到达机场）次数减一
                    it.second--;
                    // 如果后边的成功了就返回true
                    if(backtracking(result, ticketNum)){return true;}
                    it.second++;
                    result.pop_back();
                }
                
            }
            // 所有的起飞机场都尝试后，都没有成功，就返回false
            return false;
    }

    //unordered_map<出发机场，map<到达机场，次数>>targets
    unordered_map<string, map<string, int>> targets;
    vector<string> result;
};
