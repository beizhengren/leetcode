class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mapA;
        vector<int> vec;
        
        for(int i = 0; i < nums1.size(); ++i){
            mapA[nums1[i]]++;
        }
        
        for(int i = 0; i < nums2.size(); ++i){
            if(mapA[nums2[i]] != 0){
                vec.emplace_back(nums2[i]);
                mapA[nums2[i]]--;
            }
        }
        return vec;
    }
};
