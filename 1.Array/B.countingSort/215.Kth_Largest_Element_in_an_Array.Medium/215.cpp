//solution 1
///https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/215-by-ikaruga/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, greater<int> > pq;
        for(auto& n : nums)
        {
            if(pq.size() == k && pq.top() >= n) continue;
            pq.push(n);
            if(pq.size() > k)
                pq.pop();
            
        }
        return pq.top();
    }
};

//solution 2
//
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> mset(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            mset.erase(mset.begin());
        }
        return *mset.begin();
    }
};
