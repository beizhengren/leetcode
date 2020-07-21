class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> setA(nums1.begin(), nums1.end());
        set<int> setB;//保证结果的唯一性。
        for(const auto i : nums2){
            if(setA.find(i) != setA.end()){
                setB.insert(i);
            }
        }
        return vector<int>(setB.begin(), setB.end());
    }
};
