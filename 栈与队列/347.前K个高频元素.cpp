class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //key: element; value: times
        unordered_map<int, int> umap;
        for (auto& num : nums) {
            umap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, MyCompare> pq;
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            pq.push(*it);
            //或者pq.size() > k
            if (pq.size() == k + 1) {
                pq.pop();
            }
        }

        vector<int> res(pq.size(), 0);
        //由于堆顶的元素是最小的，如果K个频次从大到小排列应该是倒序存储。
        for (int i = pq.size() - 1; i >= 0; --i) {
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
private:
    struct MyCompare {
        bool operator()(pair<int, int> p1, pair<int, int> p2){
            return p1.second > p2.second;
        }
    };
};
